#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct 
{
    char name[260];
    int level;
    int is_dir;
    char full_path[1024];
}DirectoryEntry;


struct dirent
{
	long		d_ino;		/* Always zero. */
	unsigned short	d_reclen;	/* Always zero. */
	unsigned short	d_namlen;	/* Length of name in d_name. */
	char		d_name[260]; /* [FILENAME_MAX] */ /* File name. */
};
/* dùng readdir nó sẽ trả về thông tin của 1 mục */

int check_dir(const char d_name[260]){
    const char *c_duyet = d_name;
    c_duyet++;
    while (*c_duyet != '\0')
    {
        if (*c_duyet == '.')
        {
            return 0;
        }
        c_duyet++;
    }
    return 1;
}

int f_storeDir(const char *current_dir, DirectoryEntry *entries, int level, int count){
    struct dirent *entry;
    DIR *dir;
    dir = opendir(current_dir);
    while ((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            char path[1024];
            snprintf(path,sizeof(path),"%s/%s",current_dir,entry->d_name);
            strcpy(entries[count].name, entry->d_name);
            entries[count].is_dir = check_dir(path);
            entries[count].level = level;
            strcpy(entries[count].full_path, path);
            //printf("%s\n",path);
            count++;
            if(entries[count-1].is_dir){
                count = f_storeDir(path, entries,level+1, count);
            }
        }
    }
    closedir(dir);
    return count;
}

void write_iflag(const DirectoryEntry *entries,const int count){
    int i;
    for (i = 0; i < count;)
    {
        int j = i+1;
        for(j;entries[j].is_dir==0 && entries[i].level < entries[i+1].level;j++){
            const char *duyet = entries[j].name;
            while (*duyet !='\0')
            {
                duyet++;
                if(*duyet =='.'){
                    duyet++;
                    if(*duyet == 'h'){
                        printf("%s\n",entries[i].full_path);
                        i++;
                        break;
                    }
                }
            }
        }
        i++;
    }
}

void write_source(const DirectoryEntry *entries, const int count){
    int i;
    for ( i = 0; i < count; i++)
    {
        if(entries[i].is_dir == 0){
            const char *duyet = entries[i].name;
            while (*duyet != '\0')
            {
                duyet++;
                if(*duyet=='.'){
                    duyet++;
                    if (*duyet=='c')
                    {
                        printf("%s\n",entries[i].full_path);
                        break;
                    }
                    
                }
            }
        }
    }
    
}

void create_makefile(DirectoryEntry *entries, int count){
    FILE *fp = fopen("Makefile", "w");
    fprintf(fp,"# Trinh bien dich va co bien dich\n"
        "CC = gcc\n"
        "CFLAGS = -Wall -g\\\n");
    //write_iflags(fp,entries,count);
}



int main(){
    DirectoryEntry entries[100];
    int count = 0;
    count = f_storeDir(".",entries, 0,count);

    write_iflag(entries,count);

    write_source(entries,count);
}