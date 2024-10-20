CLIENT_DIR = client
MAKEFILE = $(CLIENT_DIR)/Makefile

TARGET_CLIENT = $(CLIENT_DIR)/bin/gmp

all:
	$(MAKE) -C $(CLIENT_DIR)

run: all
	@$(TARGET_CLIENT)

get_target:
	@echo $(TARGET_CLIENT)

clean:
	$(MAKE) -C $(CLIENT_DIR) clean

.PHONY: all run get_target clean
