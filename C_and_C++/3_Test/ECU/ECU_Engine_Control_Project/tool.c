#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

// cau truc luu thong tin

typedef struct{
    char name[256];
    int level;
    int is_dir;
    char full_path[1024];
}DirectoryEntry;


// check file or dir

int is_directory(const char *path){
    struct stat statbuf;

    if(stat(path, &statbuf) != 0){
        return 0;
    }

    return S_ISDIR(statbuf.st_mode);

}

// Doc thu muc va file

int doc_thu_muc_va_file(const char *dir_name, int level, DirectoryEntry *entries, int entry_count){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(dir_name);


    while ((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

            strcpy(entries[entry_count].name, entry->d_name);
            entries[entry_count].level = level;
            entries[entry_count].is_dir = is_directory(path);
            strcpy(entries[entry_count].full_path, path);
            entry_count++;
            if(entries[entry_count -1].is_dir){
                entry_count = doc_thu_muc_va_file(path, level+1, entries, entry_count);
            }
            
        }
       
       
    }

    closedir(dir);
    return entry_count;
}

int has_h_extension(const char *filename){  //0x01 - 0x09  // 0x08
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ".h") == 0);
}

int has_c_extension(const char *filename){  //0x01 - 0x09  // 0x08
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ".c") == 0 && strcmp(filename, "tool.c")!= 0);
}

int check_thu_muc(char dirs[100][1024], int dir_count, const char *dir){
    for (int i = 0; i < dir_count; i++)
    {
       if(strcmp(dirs[i], dir) == 0){   // thu muc ton tai
        return 1;
       }
    }

    return 0;
    
}


int add_unique_directory(char dirs[100][1024], int dir_count, const char *dir){
    if(!check_thu_muc(dirs, dir_count, dir)){
        strcpy(dirs[dir_count], dir);
        dir_count++;
    }
    return dir_count;
}


void write_cflags(FILE *fp, DirectoryEntry *entries, int entry_count){
    char dirs[100][ 1024];
    int dir_count = 0;
    for (int i = 0; i < entry_count; i++)
    {
        if(!entries[i].is_dir && has_h_extension(entries[i].name)){

            char dir[1024];
            strncpy(dir, entries[i].full_path, strrchr(entries[i].full_path, '/') - entries[i].full_path);
            dir[strrchr(entries[i].full_path, '/') - entries[i].full_path] = '\0';

             dir_count = add_unique_directory(dirs, dir_count, dir);
        }  
    }

    for (int i = 0; i < dir_count; i++)
    {
        if(i == dir_count - 1){
           fprintf(fp, "-I%s\n", dirs[i]);
        }else{
            fprintf(fp, "-I%s\\\n", dirs[i]);
        }
    }
}


void write_source(FILE *fp, DirectoryEntry *entries, int entry_count){
    fprintf(fp, "\nSRC = ");
    int first = 1;
    for (int i = 0; i < entry_count; i++)
    {
        if(!entries[i].is_dir && has_c_extension(entries[i].name)){
            if(!first){
                fprintf(fp, " \\\n");
            }
            fprintf(fp, "%s",entries[i].full_path);
            first = 0;
            
           
        }  
    }

    fprintf(fp, " \n\n");

}

void create_makefile(DirectoryEntry *entries, int entry_count){
    FILE *fp = fopen("Makefile", "w");
    if(fp== NULL){
        exit(1);
    }

    fprintf(fp, "# Trình biên dịch và cờ biên dịch"
                "\nCC = gcc"
                "\nCFLAGS = -Wall -g\\\n");

    write_cflags(fp, entries, entry_count);


    fprintf(fp, "# Thư mục chứa các tệp đối tượng (.o)"
                "\nOBJDIR = bin"
                "\n# Tệp thực thi"
                "\nTARGET = $(OBJDIR)/ecu");


    write_source(fp, entries, entry_count);



    fprintf(fp, "# Tạo các tệp đối tượng từ các tệp mã nguồn\n"
        "OBJ = $(SRC:%%.c=$(OBJDIR)/%%.o)\n\n"
        "# Quy tắc tạo tệp thực thi từ các tệp đối tượng\n"
        "$(TARGET): $(OBJ)\n"
        "\t@echo \"Linking all objects to create $(TARGET)...\"\n"
        "\t$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lpthread\n"
        "\t@echo \"Build successful!\"\n\n"
        "# Quy tắc để tạo các tệp đối tượng từ mã nguồn\n"
        "$(OBJDIR)/%%.o: %%.c\n"
        "\t@mkdir -p $(dir $@)\n"
        "\t$(CC) $(CFLAGS) -c $< -o $@\n"
        "\t@echo \"Compiled: $<\"\n\n"
        "# Quy tắc dọn dẹp các tệp đối tượng và tệp thực thi\n"
        ".PHONY: clean\n"
        "clean:\n"
        "\t@echo \"Cleaning up...\"\n"
        "\trm -rf $(OBJDIR)\n"
        "\t@echo \"Clean done!\"\n\n"
        "# Quy tắc chạy chương trình\n"
        ".PHONY: run\n"
        "run: $(TARGET)\n"
        "\t@echo \"Running simulation...\"\n"
        "\t$(TARGET)\n");

        fclose(fp);

}


void call_terminal(){
    system("make clean");
    system("make run");
}


int main(int argc, char const *argv[])
{
    int entry_count = 0;

    DirectoryEntry entries[100];
    
    entry_count = doc_thu_muc_va_file(".", 0, entries, entry_count);

    create_makefile(entries, entry_count);

    call_terminal();

    


    return 0;
}
