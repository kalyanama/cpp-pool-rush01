#!/bin/bash

PREFIX="$PWD/build"
DEP_DIR="$PWD/downloads"
PROJ_ROOT="$PWD"

mkdir -p $PREFIX $DEP_DIR

if [ ! -f $PREFIX/lib/libSDL2.a ] && [ ! -d $DEP_DIR/SDL2 ]; then
	if [ ! -f $DEP_DIR/SDL2.zip ]; then
		curl -o $DEP_DIR/SDL2.zip https://www.libsdl.org/release/SDL2-2.0.8.zip;
	fi ;
	unzip $DEP_DIR/SDL2.zip -d $DEP_DIR
	mv $DEP_DIR/SDL2-2.0.8 $DEP_DIR/SDL2;
	rm -rf $DEP_DIR/SDL2.zip;
fi;

if [ ! -f $PREFIX/lib/libSDL2_image.a ] && [ ! -d $DEP_DIR/SDL2_image ]; then
	if [ ! -f $DEP_DIR/SDL2_image.zip ]; then
		curl -o $DEP_DIR/SDL2_image.zip https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.zip;
	fi ;
	unzip $DEP_DIR/SDL2_image.zip -d $DEP_DIR;
	mv $DEP_DIR/SDL2_image-2.0.3 $DEP_DIR/SDL2_image;
	rm -rf $DEP_DIR/SDL2_image.zip;
fi;

if [ ! -f $PREFIX/lib/libSDL2.a ]; then
	cd $DEP_DIR/SDL2;
	./configure --prefix=$PREFIX ;
	cd $PROJ_ROOT;
	make -C $DEP_DIR/SDL2;
	make -C $DEP_DIR/SDL2 install;
fi;

if [ ! -f $PREFIX/lib/libSDL2_image.a ]; then
	cd $DEP_DIR/SDL2_image;
	./configure --prefix=$PREFIX;
	cd $PROJ_ROOT;
	make -C $DEP_DIR/SDL2_image;
	make -C $DEP_DIR/SDL2_image install;
fi;
