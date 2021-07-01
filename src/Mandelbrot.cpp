#include "Mandelbrot.h"

Scaler Mandelbrot::makeScaler(coord_t minval, coord_t maxval, img_pos_t len) {
    double unit {(maxval - minval) / len};

    return [=] (img_pos_t position) -> coord_t {
        return minval + position * unit;
    };
}

auto Mandelbrot::pixelToComplex(const Scaler& realScaler, const Scaler& imagScaler) {
    return [=](img_pos_t x, img_pos_t y) -> Complex {
        return Complex(realScaler(x), imagScaler(y));
    };
}

count_t Mandelbrot::countIterations(const Complex& c) const {
    const coord_t topnorm = 2 * 2;

    count_t iterations = 0;
    Complex z {0, 0};

    while (norm(z) <= topnorm && iterations < maxiterations) {
        iterations++;
        z *= z;
        z += c;
    }

    return iterations;
}

sf::Color Mandelbrot::complexToColor(const Complex& c) const {
    const sf::Uint8 maxcolor = 255;
    count_t iterations = countIterations(c);
    double rate {1.0 * iterations / maxiterations};

    return sf::Color(sf::Uint8(exp(rate * maxcolor)), 0,0);
}

void Mandelbrot::plotImage(sf::Image& image) const {
    auto [width, height] = image.getSize();
    auto toComplex = pixelToComplex(makeScaler(-2.5, 1, width),
                                     makeScaler(-1, 1, height));

    for (img_pos_t y{0}; y < height; y++) {
        for (img_pos_t x{0}; x < width; x++) {
            Complex z = toComplex(x, y);
            image.setPixel(x, y, complexToColor(z));
        }
    }
}