SRC_DIR = .\
	templates\
	talker_listener \
	multi_user_chat \
	simple_server_and_client

IND_FILES = using_getaddrinfo.out \
	    using_gethostname.out

SIMPLE_SERVER_AND_CLIENT = simple_server_and_client/simple_client.out \
			   simple_server_and_client/simple_server.out

TALKER_LISTENER =	talker_listener/listener.out \
			talker_listener/talker.out \
			talker_listener/listener_dgram.out \
			talker_listener/talker_dgram.out

MULTI_USER_CHAT = 	multi_user_chat/using_select_multiuser_chat.out

TEMPLATES = 	templates/client_template.out \
		templates/server_template.out

all: $(IND_FILES) $(SIMPLE_SERVER_AND_CLIENT) $(TALKER_LISTENER) $(MULTI_USER_CHAT) $(TEMPLATE)

%.out: %.c
	gcc -o $@ $^

clean:
	rm -f $(foreach dir, $(SRC_DIR), $(dir)/*.out $(dir)/*.o)

