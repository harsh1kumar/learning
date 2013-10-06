SRC_DIR = .\
	templates\
	talker_listener \
	multi_user_chat \
	simple_server_and_client

SRC_FILES = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))

OBJ_FILES = $(SRC_FILES:.c=.out)

all: $(OBJ_FILES)

%.out: %.c
	gcc -o $@ $^

define \n


endef

clean:
	$(foreach dir, $(SRC_DIR), rm -f $(dir)/*.out $(dir)/*.o ${\n})
