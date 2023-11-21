//Team Members
//Mark Ashraf William Ibrahim      	      1900156
//Hossam El-din Adel Talaat Farag         1900969
//Mohamed Ahmed Samir Tolba               1900002
//Marco Sherif Magdy Mousa                1900285
//Mohammed Saeed Ibrahim Ibrahim Dallash  1900084


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;
static int done = 0;

/*function prototypes (for orderless use)*/
void sender(int, int);
int receiver(vector<vector<char>> &receiver_frame, bool[], int, int);


/* utility function to clear the beginning of a vector and abort of it was not empty*/
template<typename T>
void pop_front(std::vector<T> &vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

/* sender function:
*  allows user to enter elements of each frame
*  transmits frames from network layer to physical layer */
void sender(const int w, int frameCount)
{
    char input;
    char frames[frameCount][w + 1]; // 2D array to store each frame's data [Number of Frames][Window Size+1]
    int window;
    bool ack[w + 1]; //acknowledgment for each frame


    for (int i = 0; i < frameCount; i++) //prompt for and take input from user
    {
        cout << "Enter frame number " << i + 1 << " :"<< endl;

        for (int j = 0; j <= w; j++)
        {
            cin >> input;
            frames[i][j] = input;
        }
    }

// Store frames in 2D vector to pass to receiver function
    vector<vector<char>> receiverFrame;
    for (int i = 0; i < frameCount; i++)
    {
        vector<char> temp;
        for (int j = 0; j <= w; j++)
        {
            temp.push_back(frames[i][j]);
        }
        receiverFrame.push_back(temp);
    }
    for (int j = 0; j <= w; j++) //initialize all frame acknowledgements to 0
    {
        ack[j] = false;
    }
    for (int i = 0; i < frameCount;)
    {
        /*determine window according to window size and remaining frames to be sent*/
        window = ((frameCount - i) < w) ? (frameCount - i) : (w);

        /*Display frames Sent*/
        cout << "\n Frames Sent : " << window << " | ";
        for (int j = i; j < i + window; j++)
        {
            for (int l = 0; l <= w; l++)
            {
                cout << frames[j][l] << " ";
            }
            cout << "\n\t\t   ";
        }
        int compare_value = i;
        i = receiver(receiverFrame, ack, window, w);
        /* compare i with i before sending last batch of frames, if they match then receiver didn't receive anything and start retransmission*/
        if (i == compare_value)
            cout << "\n Timed out, resending frame....";
    }
}

int receiver(vector<vector<char> > &receiver_frame, bool ack[], int win, int w) {
    int pop_counter = 0; /*counter to keep track of received frames*/
    bool random;
    for (int i = 0; i < win; i++) {
        switch (rand() % 4) {
            case 0:
            case 1:
            case 2:
                random = true;
                break;
            default:
                random = false;
        }
        ack[i] = random;
    }
    /*Display received frames*/
    cout << "\n Frames received";
    if (win % 100 > 9)
        cout << " ";
    cout << "| ";
    for (int i = 0; i < win && ack[i]; i++, done++) {
        for (int l = 0; l <= w; l++) {
            cout << receiver_frame[i][l] << " ";
        }
        pop_counter++;
        cout << "\n\t\t  ";
    }
    for (int j = 0; j < pop_counter; j++) {
        pop_front(receiver_frame); /*remove received frames from frames vector*/
    }
    cout << endl;
    return done;
}

int main() {
    int no_of_frames;
    int seq_nr;
    cout << "Number of frames: "; // get number of frames from user
    cin >> no_of_frames;
    cout << endl;
    cout << "Sequence number: ";//get sequence number from user
    cin >> seq_nr;
    cout << endl;
    sender(pow(2, seq_nr - 1), no_of_frames);

}
