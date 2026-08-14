#include "game_state.h"
#include "currentsessiondata.h"
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <iostream>

GameState::GameState(VGame *_game)
{
    std::cout << "Constructing GameState" << std::endl;
    this->gsCycle = 0;
    // will be set by game speed;
    this->incrementGECycleAfterGSCcycle = 1000;
    this->vGame = _game;
    texture.loadFromFile("/home/phil/Documents/Projects/spacemaybe/code/spacemaybe/src/Resources/Images/Backgrounds/bg1.png");

    // create a scenegraph;
    // go through all planets and populate the scenenode
    GameEngine *gameEngine = this->vGame->getGameEngine();

    // build a scene graph based on the current gameObjs;
    for (auto i = gameEngine->getGameObjs()->getPlanets().begin(); i != gameEngine->getGameObjs()->getPlanets().end(); ++i)
    {
        // add the planet to the scene graph
    }

    // initialize views based on current window size
    sf::RenderWindow *win = this->vGame->getMainWindow();
    sf::Vector2u winSize = win->getSize();

    // layout fractions
    float infoWidthFrac = 0.22f;     // left column for information
    float controlHeightFrac = 0.18f; // bottom row for controls

    // main world view (center pane)
    this->mainView.reset(sf::FloatRect(0.f, 0.f, 2048.f, 1400.f));
    this->mainView.setViewport(sf::FloatRect(infoWidthFrac, 0.f, 1.f - infoWidthFrac, 1.f - controlHeightFrac));

    // info view (left column)
    this->infoView.reset(sf::FloatRect(0.f, 0.f, (float)winSize.x * infoWidthFrac, (float)winSize.y * (1.f - controlHeightFrac)));
    this->infoView.setViewport(sf::FloatRect(0.f, 0.f, infoWidthFrac, 1.f - controlHeightFrac));

    // control view (bottom row)
    this->controlView.reset(sf::FloatRect(0.f, 0.f, (float)winSize.x, (float)winSize.y * controlHeightFrac));
    this->controlView.setViewport(sf::FloatRect(0.f, 1.f - controlHeightFrac, 1.f, controlHeightFrac));

    // init button state and font
    this->showFriendlyPlanets = false;
    this->showEnemyPlanets = false;
    this->showNeutralPlanets = false;
    this->wasMousePressed = false;
    this->fontLoaded = false;
    // try bundled font paths first, then common system path
    const char *tryPaths[] = {
        "Resources/Fonts/DejaVuSans.ttf",
        "src/Resources/Fonts/DejaVuSans.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
        NULL};
    for (int p = 0; tryPaths[p] != NULL; ++p)
    {
        const char *fp = tryPaths[p];
        if (this->font.loadFromFile(fp))
        {
            this->fontLoaded = true;
            std::cout << "Loaded font from: " << fp << std::endl;
            break;
        }
    }
}

void GameState::update(const float &dt)
{
    // std::cout << "GameState:Update" << std::endl;
    GameEngine *gameEngine = this->vGame->getGameEngine();
    if (this->gsCycle > this->incrementGECycleAfterGSCcycle)
    {
        gameEngine->executeCycle();
        this->gsCycle = 0;
    }
    else
    {
        this->gsCycle++;
    }
    // no demo counter when engine is inactive

    this->top_left_icon.setRadius(20.f);
    this->top_left_icon.setPosition(0.f, 0.f);
    this->top_left_icon.setFillColor(sf::Color::Red);

    this->top_right_icon.setRadius(20.f);
    this->top_right_icon.setPosition(this->mainView.getSize().x - 40.f, 0.f);
    this->top_right_icon.setFillColor(sf::Color::Black);

    this->bottom_right_icon.setRadius(20.f);
    this->bottom_right_icon.setPosition(this->mainView.getSize().x - 40.f, this->mainView.getSize().y - 40.f);
    this->bottom_right_icon.setFillColor(sf::Color::Green);

    this->bottom_left_icon.setRadius(20.f);
    this->bottom_left_icon.setPosition(0.f, this->mainView.getSize().y - 40.f);
    this->bottom_left_icon.setFillColor(sf::Color::Magenta);
    // create the four absoloute corners at the world boundries

    sf::RenderWindow *win = this->vGame->getMainWindow();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*win);
    // detect clicks inside control view button area
    sf::Vector2u winSize = win->getSize();
    float controlHeightFrac = 0.18f;
    float controlHpx = (float)winSize.y * controlHeightFrac;

    // map mouse to control view coordinates
    bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    sf::Vector2f mouseInControl = win->mapPixelToCoords(mousePos, this->controlView);

    // button rect in control view coords (matches render)
    sf::FloatRect friendlyPlanetsBtnRect(10.f, 10.f, 140.f, controlHpx - 20.f);
    sf::FloatRect neutralPlanetsBtnRect(160.f, 10.f, 140.f, controlHpx - 20.f);
    if (mousePressed && !this->wasMousePressed)
    {
        if (friendlyPlanetsBtnRect.contains(mouseInControl))
        {
            this->showFriendlyPlanets = !this->showFriendlyPlanets;
            std::cout << "showFriendlyPlanets toggled: " << this->showFriendlyPlanets << std::endl;
        } else if (neutralPlanetsBtnRect.contains(mouseInControl)) {
            this->showNeutralPlanets = !this->showNeutralPlanets;
            std::cout << "showNeutralPlanets toggled: " << this->showNeutralPlanets << std::endl;
        }
    }

    
    this->wasMousePressed = mousePressed;

    sf::Vector2f mousePosF = this->vGame->getMainWindow()->mapPixelToCoords(mousePos);
    std::cout << "x:" << mousePosF.x << " y:" << mousePosF.y << "\n";
}

void GameState::render(sf::RenderTarget *target)
{
    // std::cout << "GameState:Render" << std::endl;

    // Recompute layout fractions and sizes for responsive layout
    sf::RenderWindow *win = this->vGame->getMainWindow();

    this->renderMainView(win);
    this->renderInfoView(win);
    // --- Control view (bottom) ---
    // float controlHpx = (float)winSize.y * controlHeightFrac;
    this->renderControlView(win);
}

void GameState::renderMainView(sf::RenderWindow *win)
{
    sf::Vector2u winSize = win->getSize();
    float infoWidthFrac = 0.22f;
    float controlHeightFrac = 0.18f;

    // --- Main view (center) ---
    this->mainView.reset(sf::FloatRect(0.f, 0.f, 2048.f, 1400.f));
    this->mainView.setViewport(sf::FloatRect(infoWidthFrac, 0.f, 1.f - infoWidthFrac, 1.f - controlHeightFrac));

    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    this->mWorldBounds = sf::FloatRect(0.f, 0.f, this->mainView.getSize().x, 2000.f);
    sf::IntRect textureRect(mWorldBounds);
    sprite.setTextureRect(textureRect);
    sprite.setPosition(0.f, 0.f);

    // draw main world
    win->setView(this->mainView);
    win->draw(sprite);
    win->draw(this->top_left_icon);
    win->draw(this->top_right_icon);
    win->draw(this->bottom_right_icon);
    win->draw(this->bottom_left_icon);

    // If toggled, draw a list of planet names in the main view
    if (this->showFriendlyPlanets)
    {
        win->setView(this->mainView);
        std::vector<Planet *> planets = this->vGame->getGameEngine()->getGameObjs()->getPlanets();
        float sx = 10.f;
        float sy = 10.f;
        const float lineH = 26.f;
        if (this->fontLoaded)
        {
            for (size_t i = 0; i < planets.size(); ++i)
            {
                std::string planetcordinate = "(" + std::to_string(planets[i]->getUniverseCoordinate().getX()) + "," + std::to_string(planets[i]->getUniverseCoordinate().getY()) + ")";
                sf::Text t(planets[i]->getName() + " (" + planetcordinate +")", this->font, 26);
                t.setFillColor(sf::Color::White);
                t.setPosition(sx, sy + i * lineH);
                win->draw(t);
            }
        }
        else
        {
            // fallback: print to console
            for (size_t i = 0; i < planets.size(); ++i)
            {
                std::cout << "Planet: " << planets[i]->getName() << std::endl;
            }
        }
    }
}

void GameState::renderInfoView(sf::RenderWindow *win)
{
    sf::Vector2u winSize = win->getSize();
    float infoWidthFrac = 0.22f;
    float controlHeightFrac = 0.18f;
    // --- Info view (left column) ---
    float infoWpx = (float)winSize.x * infoWidthFrac;
    float infoHpx = (float)winSize.y * (1.f - controlHeightFrac);
    this->infoView.reset(sf::FloatRect(0.f, 0.f, infoWpx, infoHpx));
    this->infoView.setViewport(sf::FloatRect(0.f, 0.f, infoWidthFrac, 1.f - controlHeightFrac));

    win->setView(this->infoView);
    // background for info pane
    sf::RectangleShape infoBg;
    infoBg.setFillColor(sf::Color(40, 40, 48));
    infoBg.setSize(sf::Vector2f(infoWpx, infoHpx));
    infoBg.setPosition(0.f, 0.f);
    win->draw(infoBg);

    // (cycle display removed)
    GameEngine *gameEngine = this->vGame->getGameEngine();


    // placeholder: simple bars / panels in info pane
    sf::RectangleShape panel1(sf::Vector2f(infoWpx - 20.f, 80.f));
    panel1.setPosition(10.f, 10.f);
    panel1.setFillColor(sf::Color(70, 70, 90));
    win->draw(panel1);

    float sx = 10.f;
    float sy = 10.f;
    const float lineH = 18.f;
    std::string cycleStringInitial = "Cycle:";
    std::string cycleString = cycleStringInitial + "" + std::to_string(gameEngine->getGameObjs()->getCycle()); 
    std::cout << cycleString << std::endl;

    if (this->fontLoaded)
    {
        sf::Text t(cycleString , this->font, 14);
        t.setFillColor(sf::Color::White);
        t.setPosition(panel1.getPosition().x+sx, panel1.getPosition().y+sy);

        win->draw(t);
    }
    else
    {
        // fallback: print to console

        std::cout << cycleString << std::endl;
    }



    sf::RectangleShape panel2(sf::Vector2f(infoWpx - 20.f, 80.f));
    panel2.setPosition(10.f, 100.f);
    panel2.setFillColor(sf::Color(70, 70, 90));
    win->draw(panel2);
}

void GameState::renderControlView(sf::RenderWindow *win)
{
    sf::Vector2u winSize = win->getSize();
    float controlHeightFrac = 0.18f;
    float controlHpx = (float)winSize.y * controlHeightFrac;
    this->controlView.reset(sf::FloatRect(0.f, 0.f, (float)winSize.x, controlHpx));
    this->controlView.setViewport(sf::FloatRect(0.f, 1.f - controlHeightFrac, 1.f, controlHeightFrac));

    win->setView(this->controlView);

    sf::RectangleShape controlBg;
    controlBg.setFillColor(sf::Color(28, 28, 32));
    controlBg.setSize(sf::Vector2f((float)winSize.x, controlHpx));
    controlBg.setPosition(0.f, 0.f);
    win->draw(controlBg);

    // placeholder buttons
    float bx = 10.f;
    // toggle button for showing planet names
    sf::RectangleShape friendlyPlanetBtn(sf::Vector2f(140.f, controlHpx - 20.f));
    friendlyPlanetBtn.setPosition(10.f, 10.f);
    if (this->showFriendlyPlanets)
    {
        friendlyPlanetBtn.setFillColor(sf::Color(80, 160, 80));
    }
    else
    {
        friendlyPlanetBtn.setFillColor(sf::Color(100, 100, 120));
    }
    win->draw(friendlyPlanetBtn);

    if (this->fontLoaded)
    {
        sf::Text tbText(this->showFriendlyPlanets ? "Friendly Planets" : "Friendly Planets", this->font, 16);
        tbText.setFillColor(sf::Color::White);
        tbText.setPosition(14.f, 14.f);
        win->draw(tbText);
    }

    // placeholder buttons
    //float bx = 10.f;
    // toggle button for showing planet names
    sf::RectangleShape neutralPlanetBtn(sf::Vector2f(140.f, controlHpx - 20.f));
    neutralPlanetBtn.setPosition(160.f, 10.f);
    if (this->showNeutralPlanets)
    {
        neutralPlanetBtn.setFillColor(sf::Color(80, 160, 80));
    }
    else
    {
        neutralPlanetBtn.setFillColor(sf::Color(100, 100, 120));
    }
    win->draw(neutralPlanetBtn);

    if (this->fontLoaded)
    {
        sf::Text tbText(this->showNeutralPlanets ? "Neutral Planets" : "Neutral Planets", this->font, 16);
        tbText.setFillColor(sf::Color::White);
        tbText.setPosition(164.f, 14.f);
        win->draw(tbText);
    }


}

GameState::~GameState()
{
}