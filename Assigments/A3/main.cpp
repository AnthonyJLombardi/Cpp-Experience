#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    friend bool operator==(const Song & s1, const Song & s2);
    friend istream & operator>>(istream & in, Song & s);

    Song(): Song("invalid", "invalid",-1) {}
    Song(string t) : Song(t,"unknown", -1) {}
    Song (string t, string a, int y) : title_(t), artist_(a), year_(y) {}

    string title() const {return title_;}
    string artist() const {return artist_;}
    int year() const {return year_;}

    void set_title(string t) {title_=t;}
    void set_artist(string a) {artist_=a;}
    void set_year(int y) {year_=y;}
    void set(string t, string a, int y);
private:
    string title_;
    string artist_;
    int year_;
};
inline void Song::set(string t, string a, int y) {
    title_=t;
    artist_=a;
    year_=y;
}
inline ostream & operator<<(ostream & out, const Song & s) {
    //@param: output stream and a song object passed by constant reference
    //@return: prints out all variables related to the song object
    out << s.title() << endl << s.artist() << endl << s.year() << endl;
    return out;
}
inline istream & operator>>(istream & in, Song & s) {
    //@param: an input stream and a song passed by reference
    //@return: reads in user input from an input stream and sets the corresponding values into the song object
    getline(in,s.title_);
    getline(in, s.artist_);
    in >> s.year_;
    return in;
}
inline bool operator==(const Song & s1, const Song & s2) {
    //@param: two songs passed as constant reference
    //@return: returns true if the title, artist, and year of a song object are all exactly the same
    return (s1.title() == s2.title()) && (s1.artist() == s2.artist()) && (s1.year() == s2.year());
}

