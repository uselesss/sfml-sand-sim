all:
	g++ main.cpp -o o.o -DSFML_STATIC -static -static-libgcc -static-libstdc++ -ISFML-2.5.1\include -LSFML-2.5.1\lib -lsfml-graphics -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
