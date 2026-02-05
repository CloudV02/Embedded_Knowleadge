# Trình biên dịch và cờ biên dịch
CC = gcc
CFLAGS = -Wall -g\
-I./BSW/ECU_Abstraction/IoHwAb\
-I./BSW/MCAL\
-I./BSW/Services\
-I./RTE\
-I./SWC
# Thư mục chứa các tệp đối tượng (.o)
OBJDIR = bin
# Tệp thực thi
TARGET = $(OBJDIR)/ecu
SRC = ./BSW/ECU_Abstraction/IoHwAb/IoHwAb_LoadSensor.c \
./BSW/ECU_Abstraction/IoHwAb/IoHwAb_MotorDriver.c \
./BSW/ECU_Abstraction/IoHwAb/IoHwAb_SpeedSensor.c \
./BSW/ECU_Abstraction/IoHwAb/IoHwAb_ThrottleSensor.c \
./BSW/ECU_Abstraction/IoHwAb/IoHwAb_TorqueSensor.c \
./BSW/MCAL/Adc.c \
./BSW/MCAL/Can.c \
./BSW/MCAL/Dio.c \
./BSW/MCAL/Pwm.c \
./BSW/Services/Dcm.c \
./BSW/Services/Dem.c \
./BSW/Services/Mem.c \
./BSW/Services/Os.c \
./BSW/Services/Pdu_Router.c \
./Main.c \
./RTE/Rte_TorqueControl.c \
./SWC/Torque_Control.c 

# Tạo các tệp đối tượng từ các tệp mã nguồn
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Quy tắc tạo tệp thực thi từ các tệp đối tượng
$(TARGET): $(OBJ)
	@echo "Linking all objects to create $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lpthread
	@echo "Build successful!"

# Quy tắc để tạo các tệp đối tượng từ mã nguồn
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Quy tắc dọn dẹp các tệp đối tượng và tệp thực thi
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR)
	@echo "Clean done!"

# Quy tắc chạy chương trình
.PHONY: run
run: $(TARGET)
	@echo "Running simulation..."
	$(TARGET)
