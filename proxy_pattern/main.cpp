#include "IImage.h"
#include "ProxyImage.h"

int main() {
    ProxyImage proxy("c:/test/test.png");
    proxy.display();
}