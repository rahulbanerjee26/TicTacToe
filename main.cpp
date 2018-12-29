//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#include <tic-tac-toe/playMove.h>

using namespace std;
using namespace sf;


int main() {

    /************************************************************************************************************/
    /* The following variables define the state of the game                                                     */
    /************************************************************************************************************/

    // You should complete the following declarations
    // Make sure to initalize the variables

    // The game board array
    int gameBoard[3][3] = {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty};
    // An boolean that represents the turn in the game
    bool turn=true;
    // A boolean to represent if the move is valid
    bool validMove=true;
    // A boolean to represent if the game is over
    bool gameOver = false;
    // An integer that represents the win code
    int winCode=0;
    
    /************************************************************************************************************/
    /* Insert code that loads the various images used by the game and creates the sprites                       */
    /* The loading of the X image is shown. Repreat for the rest of the images                                  */
    /************************************************************************************************************/

    // Get the X image
    sf::Texture X_texture;
    if (!X_texture.loadFromFile("X.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite X_sprite(X_texture);
    // Get the O image
    sf::Texture O_texture;
    if (!O_texture.loadFromFile("O.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite O_sprite(O_texture);
    
    // Get the blank image
    sf::Texture blank_texture;
    if (!blank_texture.loadFromFile("blank.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite blank_sprite(blank_texture);

    /************************************************************************************************************/
    /* Insert code that creates the window and displays it                                                      */
    /************************************************************************************************************/

    // First, we find the sizes of the images so we can determine the size of the window we must create
    // The images (X, O and Black) are assumed to be square are are all of the same size
    // Thus, we just find the size of one of them

    // The tile size is the size of the images
    const int tileSize = X_texture.getSize().x;

    // The cell borders (thick lines) are rectangles
    // The size of these rectangles is 1/20th of the size of the tile by 3 cell sizes plus 2 barWidth's
    const int barWidth = tileSize/20;
    const int barHeight = 3*boardSize*tileSize + (boardSize-1)*barWidth;

    // The size of the window in pixels can now be calculated
    const int windowSize = boardSize*tileSize + (boardSize-1)*barWidth;

    // Create the main window: it has a title bar and a close button, but is not resizable
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "ECE244 Tic-Tac-Toe", sf::Style::Titlebar | sf::Style::Close);
    //sf::RenderWindow myFirstWindow(VideoMode(800, 600), "ECE244 Window",Style::Titlebar | Style::Close);
    // Set the Icon that appears in the task bar when the window is minimized
    // Insert you code here, see the lab handout
    sf::Image myFirstWindowIcon;
    if (!myFirstWindowIcon.loadFromFile("icon.jpg")) {
        return EXIT_FAILURE;
    }
    window.setIcon(myFirstWindowIcon.getSize().x,
    myFirstWindowIcon.getSize().y,
    myFirstWindowIcon.getPixelsPtr());

    // Create the horizonal (vertical) borders as rectangles of sizes barWidth and barHeight (berHeight and barWidth)
    // Insert your code here
    sf::RectangleShape myOwnRectangle(sf::Vector2f(barWidth,barHeight));
    myOwnRectangle.setFillColor(sf::Color(0,0,0));
    /************************************************************************************************************/
    /* This is the main event loop of the code                                                                  */
    /************************************************************************************************************/

    // Start the game loop that runs as long as the window is open
    while (window.isOpen()) {
        // The event
        sf::Event event;

        // Process the events
        while (window.pollEvent(event)) {

            // This is the handling of the close window event
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            // Left mouse button pressed: get the click position and play the move
            // is_game_over is a variable you should define above
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // left mouse button is pressed: get the coordinates in pixels
                sf::Vector2i localPosition = Mouse::getPosition(window);
                int xPosition= (localPosition.x)/tileSize;
                int yPosition= (localPosition.y)/tileSize;
                // Convert the pixel coordinates into game board rows and columns
                // Just divide by tileSize
                
                // Observe that the x axis is the rows and the y axis is the columns
                // Also make sure that row and column values are valid
                // Insert your code below


                // Play the move by calling the playMove function
                // Insert your code below
                playMove(gameBoard,yPosition,xPosition,turn,validMove,gameOver,winCode);
            }
        }

        // Insert code to draw the tiles using the sprites created earlier
        // You must determine the position of each cell on the grid, taking into account the width of
        // the border and then position the sprite there and draw it.
        // Draw the entire board, cell borders included,
        // reflecting any move that has just happened (check the gameBoard array)
        // Further, if the game is over and one player wins, you must create and draw a rectangle of
        // windowSize width and 10 pixels height to indicate the winning marks
        // The fill of this rectangle should be white

        // Insert your code here
        myOwnRectangle.setPosition(tileSize,0);
        window.draw(myOwnRectangle);
        myOwnRectangle.setPosition(2*tileSize+barWidth,0);
        window.draw(myOwnRectangle);    
        myOwnRectangle.setSize(sf::Vector2f(barHeight,barWidth));
        myOwnRectangle.setPosition(0,tileSize);
        window.draw(myOwnRectangle);
        myOwnRectangle.setPosition(0,2*tileSize+barWidth);
        window.draw(myOwnRectangle);
        
        for(int row=0;row<3;row++){
            float positionY=row*(tileSize+barWidth);
            for(int col=0;col<3;col++){
                float positionX=col*(tileSize+barWidth);
                if(gameBoard[row][col]==0){
                    blank_sprite.setPosition(positionX,positionY);
                    window.draw(blank_sprite);
                }
                if(gameBoard[row][col]==1){
                    X_sprite.setPosition(positionX,positionY);
                    window.draw(X_sprite);
                }
                if(gameBoard[row][col]==-1){
                    O_sprite.setPosition(positionX,positionY);
                    window.draw(O_sprite);
                }            
                      
            }         
        }
        sf::RectangleShape winRectangle(sf::Vector2f(barWidth,barHeight));
        winRectangle.setFillColor(sf::Color::White);
        if(winCode ==1){
            winRectangle.setPosition(0,tileSize/2);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            window.draw(winRectangle);
        }
        if(winCode ==2){
            winRectangle.setPosition(0,3*tileSize/2+barWidth);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            window.draw(winRectangle);
        }
        if(winCode ==3){
            winRectangle.setPosition(0,5*tileSize/2+barWidth);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            window.draw(winRectangle);
        }
        if(winCode ==4){
            winRectangle.setPosition(tileSize/2,0);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            winRectangle.setRotation(90);
            window.draw(winRectangle);
        }
        if(winCode ==5){
            winRectangle.setPosition(3*tileSize/2+1.5*barWidth,0);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            winRectangle.setRotation(90);
            window.draw(winRectangle);
        }
        if(winCode ==6){
            winRectangle.setPosition(5*tileSize/2+2.5*barWidth,0);
            winRectangle.setSize(sf::Vector2f(windowSize,10));
            winRectangle.setRotation(90);
            window.draw(winRectangle);
        }
        if(winCode ==7){
            winRectangle.setPosition(0,0);
            winRectangle.setSize(sf::Vector2f(10,1.414*windowSize));
            winRectangle.setRotation(-45);
            window.draw(winRectangle);
        }
        if(winCode ==8){
            winRectangle.setPosition(3*tileSize,-8);
            winRectangle.setSize(sf::Vector2f(10,1.414*windowSize));
            winRectangle.setRotation(45);
            window.draw(winRectangle);
        }
        // Display to the window
        window.display();
    }

    return EXIT_SUCCESS;
}