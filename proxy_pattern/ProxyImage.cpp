#include "IImage.h"
#include "Image.h"
#include "ProxyImage.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

ProxyImage::ProxyImage(char const *path) {
    int length = strlen(path);
    m_path = (char *)malloc(strlen(path) * sizeof(char *));
    memcpy(m_path, path, length);
    m_image = NULL;
}

ProxyImage::~ProxyImage() {
    free(m_path);
    delete m_image;
}

void ProxyImage::display() {
    if (NULL == m_image) {
        cout << "[ProxyImage::" << __FUNCTION__ << "] " << "create image object" << endl;
        m_image = new Image(m_path);
    }
    m_image->display();
}