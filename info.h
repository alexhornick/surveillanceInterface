#ifndef INFO_H
#define INFO_H
#include <QPoint>
#include <QtGlobal>
#include <vector>
#include <string>
using namespace std;
class Info
{
public:
    vector<string> videoName; //for checked info
    vector<string> videoName2; //for video clicks
    vector<string> videoName3; //for concealing/prob
    vector<string> partChecked;
    vector<string> characteristicChecked;
    vector<string> timestamp;
    vector<string> timeLocation;
    vector<string> clickPos;
    vector<string> concealing;
    vector<int> probability;
    vector<string> comment;
    vector<string> characteristicNum;
    vector<string> orderOfClicks; //within timestamp
    vector<string> sequenceOfChecks; //from 1 to however many within video
    vector<string> sequencePlayed;
    vector<string> sequencePlayed2;
    vector<string> sequencePlayed3;
    vector<string> orderCheckedTotal;
    vector<string> bodyPartNum;
    vector<int> laterality;
    vector<string> realTime1;
    vector<string> realTime2;
    vector<string> lateralityText;
    int participantNumber;
    vector<qint64> intTime;


    struct BodyPart
    {
        string name;
        vector<string> data;
        vector<string> charNum; //characteristic Number
        bool bilateral;
    };
    BodyPart createBodyPart(string n, string d, bool b);
    //string bodyNumber;

public:
    Info();
    void addToChecked(string);
    void writeData();
    void addToTimestamp(string);
    void addToClickPos(string);
    void setConcealing(bool);
    void setProbability(int);
    vector<BodyPart> bodyparts;
    void addVideoName(string);
    void addToTimeLocation(string);
    void addVideoName2(string);
    void addVideoName3(string);
    void addCharNum(string);
    void addOrderClicks();
    static bool is_file_exist(string);
    void addToSequencePlayed(string);
    void addToSequencePlayed2(string);
    void addToSequencePlayed3(string);
    void addToOrderCheckedTotal();
    void addBodyPartNum(string);
    void addToRealTime1(string);
    void addToRealTime2(string);
    void addParticipantNum(int);
    void addToIntTime(qint64);
};

#endif // INFO_H
