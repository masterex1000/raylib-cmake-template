# CMake Raylib Project Template

A pretty minimal raylib project that uses cmake. It includes a couple things that
I usually use in my personal projects (namely agui.h and some config options).

Other than putting the inital `main.cpp` file the `src/` directory, it doesn't guide any sort of
file structure or project paradigm, its just a working, runable project.

## Notes

###  `include/agui.h`

This can be safely removed. It is just a small library I threw together that makes dealing with
rectangle transformations a bit easier, and have ended up using it over and over again in most of my
projects with little to no modification. Its especially usefull if you're building something with raygui.

## First Time Setup

From the root project directory run

```bash
git init # If not already initalized
git submodule add --depth 1 -- https://github.com/raysan5/raylib libs/raylib
```

## All other times setup (eg. you're recloning your setup repo)

```bash
git submodule init
git submodule update
```