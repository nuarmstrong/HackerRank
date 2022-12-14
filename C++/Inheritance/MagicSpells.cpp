#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */

  if (Fireball* fire = dynamic_cast<Fireball*>(spell)) {
      fire->revealFirepower();
  }
  else if (Frostbite* frost = dynamic_cast<Frostbite*>(spell)) {
      frost->revealFrostpower();
  }
  else if (Thunderstorm* thunder = dynamic_cast<Thunderstorm*>(spell)) {
      thunder->revealThunderpower();
  }
  else if (Waterbolt* water = dynamic_cast<Waterbolt*>(spell)) {
      water->revealWaterpower();
  }
  else {
    string spl = spell->revealScrollName(), jnl = SpellJournal::read();
    int s = spl.length(), l = jnl.length();
    
    // string B[l + 1];
    string MEMO[s + 1][l + 1];

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < l; j++) {
            MEMO[i][j] = "";
        }
    }

    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= l; j++) {
            if (spl[i - 1] == jnl[j - 1]) {
                MEMO[i][j] = MEMO[i - 1][j - 1] + spl[i - 1];
            }
            else {
                MEMO[i][j] = std::max(MEMO[i - 1][j], MEMO[i][j - 1]);
            }
        }
    }

    cout << MEMO[s][l].length() << endl;
    
}
  

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}