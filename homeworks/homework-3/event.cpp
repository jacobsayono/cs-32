class Event {
    public:
        Event(string name) {
            m_name = name;
        }
        virtual string need() const = 0;
        string name() const {
            return m_name;
        }
        virtual bool isSport() const {
            return true;
        }
        virtual ~Event() {}
    private:
        string m_name;
};

class BasketballGame : public Event {
    public:
        BasketballGame(string name) : Event(name) {}
        virtual string need() const {
            return "hoops";
        }
        virtual ~BasketballGame() {
            cout << "Destroying the " + this->name() + " basketball game"  << endl;
        }
};


class Concert : public Event {
    public:
        Concert(string name, string genre) : Event(name), m_genre(genre) {};
        virtual string need() const {
            return "a stage";
        }
        virtual bool isSport() const {
            return false;
        }
        virtual ~Concert() {
            cout << "Destroying the " + this->name() + " concert" << endl;
        }
    private:
        string m_genre;
};


class HockeyGame : public Event {
    public:
        HockeyGame(string name) : Event(name) {}
        virtual string need() const {
            return "ice";
        }
        virtual ~HockeyGame() {
            cout << "Destroying the " + this->name() + " hockey game" << endl;
        }
};