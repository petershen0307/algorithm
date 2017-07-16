#ifndef __ProxyImage_h__
#define __ProxyImage_h__

class IImage;
class Image;

class ProxyImage : public IImage {
public:
    ProxyImage(char const *path);
    ~ProxyImage();
    void display();
private:
    Image *m_image;
    char *m_path;
};

#endif //__ProxyImage_h__