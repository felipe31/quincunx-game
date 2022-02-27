class GameStateSingleton {
protected:
    GameStateSingleton() : creditsCurrent(0), creditsIn(0), creditsOut(0), matchCount(0) {}

    int creditsCurrent, creditsIn, creditsOut, matchCount;
    static GameStateSingleton* instance;

public:
    static GameStateSingleton& getInstance() {
        if (instance == 0)
            instance = new GameStateSingleton();
        return *instance;
    }

    int getCreditsCurrent();
    void setCreditsCurrent(int newCreditsCurrent);

    int getCreditsIn();
    void setCreditsIn(int newCreditsIn);

    int getCreditsOut();
    void setCreditsOut(int newCreditsOut);

    int getMatchCount();
    void setMatchCount(int count);
};