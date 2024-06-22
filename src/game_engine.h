class GameEngine {
 public:
    GameEngine();
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