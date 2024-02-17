#include <iostream>
#include <string>

using namespace std;

struct Song {
    string name;
    string producer;
    string singer;
    string genre;
};

class Node {
public:
    Song data;
    Node* prev;
    Node* next;
};

class Playlist {
public:
    Node* head;
    Node* tail;
    Node* currentSong;

    Playlist() : head(nullptr), tail(nullptr), currentSong(nullptr) {}

    ~Playlist() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        currentSong = nullptr;
    }

    void addSong(const Song& song) {
        Node* newNode = new Node;
        newNode->data = song;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
            currentSong = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayCurrentSong() const {
        if (currentSong) {
            cout << "Current Song: " << currentSong->data.name << endl;
            cout << "Producer: " << currentSong->data.producer << endl;
            cout << "Singer: " << currentSong->data.singer << endl;
            cout << "Genre: " << currentSong->data.genre << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    void nextSong() {
        if (currentSong && currentSong->next) {
            currentSong = currentSong->next;
            displayCurrentSong();
        } else {
            cout << "No next song available." << endl;
        }
    }

    void prevSong() {
        if (currentSong && currentSong->prev) {
            currentSong = currentSong->prev;
            displayCurrentSong();
        } else {
            cout << "No previous song available." << endl;
        }
    }

    void displaySongsByGenre(const string& genre) const {
        Node* current = head;
        bool found = false;
        while (current) {
            if (current->data.genre == genre) {
                cout << "Song: " << current->data.name << ", Producer: " << current->data.producer << ", Singer: " << current->data.singer << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No songs found in the genre: " << genre << endl;
        }
    }

    void displaySongsBySinger(const string& singer) const {
        Node* current = head;
        bool found = false;
        while (current) {
            if (current->data.singer == singer) {
                cout << "Song: " << current->data.name << ", Producer: " << current->data.producer << ", Genre: " << current->data.genre << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No songs found by singer: " << singer << endl;
        }
    }

    void displaySongsByProducer(const string& producer) const {
        Node* current = head;
        bool found = false;
        while (current) {
            if (current->data.producer == producer) {
                cout << "Song: " << current->data.name << ", Singer: " << current->data.singer << ", Genre: " << current->data.genre << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No songs found produced by: " << producer << endl;
        }
    }
};

int main() {
    Playlist playlist;

    Song song1 = {"Desi Girl", "Sony Music", "Vishal-Shekhar", "Bollywood"};
    playlist.addSong(song1);
    Song song2 = {"With you", "Gminxr", "AP Dhillon", "Vibe"};
    playlist.addSong(song2);
    Song song3 = {"Drama Queen", "Dharma Production", "Vishal-Shekhar", "Bollywood"};
    playlist.addSong(song3);
    Song song4 = {"Alfaazo", "Big Bang Music", "Mitraz", "Romantic"};
    playlist.addSong(song4);
    Song song5 = {"One Shot 2 Shot", "Luis Resto", "Eminem", "Hip Hop"};
    playlist.addSong(song5);
    Song song6 = {"Akhiyaan", "Mitraz", "Mitraz", "Chill"};
    playlist.addSong(song6);

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Display current song" << endl;
        cout << "2. Play next song" << endl;
        cout << "3. Play previous song" << endl;
        cout << "4. Display songs by genre" << endl;
        cout << "5. Display songs by singer" << endl;
        cout << "6. Display songs by producer" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playlist.displayCurrentSong();
                break;
            case 2:
                playlist.nextSong();
                break;
            case 3:
                playlist.prevSong();
                break;
            case 4: {
                string genre;
                cout << "Enter the genre: ";
                cin >> genre;
                playlist.displaySongsByGenre(genre);
                break;
            }
            case 5: {
                string singer;
                cout << "Enter the singer: ";
                cin >> singer;
                playlist.displaySongsBySinger(singer);
                break;
            }
            case 6: {
                string producer;
                cout << "Enter the producer: ";
                cin >> producer;
                playlist.displaySongsByProducer(producer);
                break;
            }
            case 7:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
