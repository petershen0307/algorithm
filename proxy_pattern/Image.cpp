#include "IImage.h"
#include "Image.h"

#include <iostream>
using namespace std;
Image::Image(char *path) {
    load(path);
}

Image::~Image() {

}

void Image::display() {
    cout << "[Image::" << __FUNCTION__ << "] " << "display the image" << endl;
}

void Image::load(char *path) {
    cout << "[Image::" << __FUNCTION__ << "] " << "load path:" << path << endl;
}