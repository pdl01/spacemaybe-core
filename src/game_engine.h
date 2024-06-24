#ifndef SRC_GAME_ENGINE_H_
#define SRC_GAME_ENGINE_H_

class GameEngine {
 public:
    GameEngine();
    void initialize();
    void start();

//    void setExit(bool _exit);
//    bool getExit();
    
//    void stop();
//void start();
//    
 protected:
 private:
    bool exit;
    int cycle;

    void execute();
    
};

#endif