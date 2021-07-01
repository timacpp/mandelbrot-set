#include "Mandelbrot.h"

int main() {
    /* Generation of empty image with specified resolution. */
    sf::Image mandelbrotImage;
    mandelbrotImage.create(defaults::width, defaults::height);

    /* Plotting the Mandelbrot set on top of the image. */
    Mandelbrot mandelbrot;
    mandelbrot.plotImage(mandelbrotImage);

    /* Interpreting the image as an object texture. */
    sf::Texture mandelbrotTexture;
    mandelbrotTexture.loadFromImage(mandelbrotImage);
    mandelbrotTexture.setSmooth(true);

    /* Creation of a sprite with a texture of the set. */
    sf::Sprite mandelbrotSprite;
    mandelbrotSprite.setTexture(mandelbrotTexture);

    /* Customization of the main window. */
    sf::VideoMode video(defaults::width, defaults::height);
    sf::RenderWindow window(video, "Mandelbrot set", sf::Style::Fullscreen);

    /* Displaying window with sprite and handling events. */
    sf::Event event{};

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed)
                window.close();
        }

        window.draw(mandelbrotSprite);
        window.display();
    }

    return 0;
}