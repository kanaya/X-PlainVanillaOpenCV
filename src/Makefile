%.o: %.c
	cc -c $<

all: capturesample

capturesample: capturesample.o
	cc -o $@ $^ -I/usr/local/include -L/usr/local/lib -lopencv_legacy -lopencv_highgui

