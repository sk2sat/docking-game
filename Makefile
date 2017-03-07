MINGW = wine ~/MinGW/bin/
CXX = $(MINGW)g++.exe

DXLIB  = ~/DxLib/4_5_2
DXLIB_CXXFLAGS = -DDX_GCC_COMPILE -DDX_NON_INLINE_ASM
DXLIB_LDFLAGS  = -lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib \
-ltiff -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static \
-lbulletdynamics -lbulletcollision -lbulletmath -lopusfile -lopus -lsilk_common -lcelt -mwindows

INCDIR = -I $(DXLIB)
LIBDIR = -L $(DXLIB)

CXXFLAGS = $(INCDIR) $(DXLIB_CXXFLAGS)
LDFLAGS  = $(LIBDIR) $(DXLIB_LDFLAGS)

TARGET = test.exe
OBJS = main.o

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

default:
	make $(TARGET)

$(TARGET):$(OBJS)
	$(CXX) -static-libgcc -static-libstdc++ -o $@ $^ -lstdc++ $(LDFLAGS) -lgcc

run:$(TARGET)
	wine $(TARGET)


