#ifndef __Image_h_
#define __Image_h_

class IImage;

class Image : public IImage {
public:
    Image(char *path);
    ~Image();
    void display();
private:
    void load(char *path);
};

#endif //__Image_h_