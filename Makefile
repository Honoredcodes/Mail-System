E = g++
EFLAG = -std=c++17 \
        -stdlib=libc++ \
        -Imodules/includes \
        -Imodules/service \
        -Imodules/utility
# -Imodules/mail \

SOURCE = \
main.cpp \
modules/service/filesys.cpp \
modules/utility/utils.cpp 
# modules/mail/app.cpp \

APP = echomail

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
  EFLAG += -I/opt/homebrew/Cellar/jsoncpp/1.9.6/include -I/usr/include
  LDFLAGS = -L/opt/homebrew/Cellar/jsoncpp/1.9.6/lib \
            -L/opt/homebrew/opt/curl/lib \
            -ljsoncpp -lcurl
else ifeq ($(UNAME_S),Linux)
  EFLAG += -I/usr/include/jsoncpp
  LDFLAGS = -ljsoncpp -lcurl
endif

all:
	@echo "Please wait, while the program is being compiled..."
	@$(E) $(EFLAG) $(SOURCE) -o $(APP) $(LDFLAGS)

clean:
	@echo "Cleaning and removing previous build..."
	rm -f $(APP)