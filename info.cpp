#include "info.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QtGlobal>

using namespace std;

Info::Info()
{
    bodyparts.push_back(createBodyPart("Head", "Facing forward, Not moving around",false));
    bodyparts.push_back(createBodyPart("Shoulders", "Stiff, Rigid, Limited movement",true));
    bodyparts.push_back(createBodyPart("Arms", "Asymmetrical arm swing, Restricted or limited arm swing, Unnatural arm swing",true));
    bodyparts.push_back(createBodyPart("Torso", "Rigid, Stiff, Too upright/erect, Slightly hunched",false));
    bodyparts.push_back(createBodyPart("Legs/Gait", "Stiff, Unnatural, Rigid, Controlled, Small strides, Deliberate",true));
    bodyparts.push_back(createBodyPart("Demeanor", "Careful, Nervous, Relaxed",false));
}

Info::BodyPart Info::createBodyPart(string n, string d, bool b)
{
    BodyPart part;
    part.name = n;
    part.bilateral = b;
    while(d.find(",")!= -1) {
        part.data.push_back(d.substr(0, d.find(",")));
        d = d.substr(d.find(",") + 2, d.size() - d.find(",") - 2);
    }


    part.data.push_back(d);
    return part;
}

void Info::addToChecked(string s) {
    string characteristic;
    string::size_type pos = s.find(',');
       if(s.npos != pos) {
           characteristic = s.substr(pos + 1);
           s = s.substr(0, pos);
       }

    partChecked.push_back(s);

    if (characteristic.rfind("Left") != -1) {
        characteristic = characteristic.substr(0, characteristic.size() - 4);
        laterality.push_back(1);
        lateralityText.push_back("Left");
    } else if (characteristic.rfind("Right")!=-1) {
        characteristic = characteristic.substr(0, characteristic.size() - 5);
        laterality.push_back(2);
        lateralityText.push_back("Right");
    } else if (characteristic.rfind("Both") != -1) {
        characteristic = characteristic.substr(0, characteristic.size() - 4);
        laterality.push_back(3);
        lateralityText.push_back("Both");
    } else {
        laterality.push_back(0);
        lateralityText.push_back("Not Applicable");
    }

    characteristicChecked.push_back(characteristic);


}

void Info::writeData() {
    addToOrderCheckedTotal();
    addOrderClicks();
    string fileName = "detectThreat";
    string fileExtension = "detectThreat.csv";
    string extension = ".csv";
    int i = 1;
    string j = std::to_string(i);

    while(is_file_exist(fileExtension))
    {
        j = std::to_string(i);
        fileExtension = (fileName+j) + extension;
        i++;
    }

    ofstream outputFile(fileExtension);         //Opening file to print info to

    outputFile << "Checked Data" << endl;
    outputFile << "Participant Number," << "Video Name,"  << "Sequence Played,"<< "Body Part," << "Body Part Number," <<  "Characteristic,"<< "Characteristic Number," << "Laterality,"  << "Laterality Number," << "Time Stamp," << "Real Time,"<<"Order Checked Within TimeStamp, " << "Order Checked Within Video" << endl;

    for(int i=0; i < partChecked.size(); i++)
    {
        outputFile << participantNumber << "," << videoName.at(i) <<"," << sequencePlayed.at(i) << "," << partChecked.at(i) << "," << bodyPartNum.at(i) << "," << characteristicChecked.at(i) << ","   << characteristicNum.at(i) << ","  <<lateralityText.at(i) << "," << laterality.at(i) << ","<< timestamp.at(i) << "," << realTime1.at(i) << ","<< orderOfClicks.at(i) << "," << orderCheckedTotal.at(i) << endl;
    }

    outputFile << endl << endl;
    outputFile << "Video Clicks" << endl;
    outputFile << "Participant Number," << "Video Name,"  << "Sequence Played,"<< "Time Location," <<"Real Time," << "Click Position X," << "Click Position Y, " <<endl;
    for(int i = 0; i < videoName2.size(); i++)
    {
        outputFile  << participantNumber << "," << videoName2.at(i) << "," << sequencePlayed2.at(i) << "," << timeLocation.at(i) << "," << realTime2.at(i) << "," << clickPos.at(i) << ","  << endl;
    }

    outputFile << endl << "Participant Number," << "Video Name," << "Sequence Played," << "Concealing?, " << "Confidence %," << endl;

    for(int i =0; i < videoName3.size(); i++)
    {
        outputFile << participantNumber << "," << videoName3.at(i)<< "," << sequencePlayed3.at(i) << "," << concealing.at(i) << "," << probability.at(i) << ","  << endl;
    }

    outputFile.close();
}

void Info::addToTimestamp(string s) {
    timestamp.push_back(s);
}

void Info::addToClickPos(string s) {
    clickPos.push_back(s);
}

void Info::setConcealing(bool b) {
    string s;
    if(b == true)
         s= "Yes";
    else
        s = "No";
    concealing.push_back(s);
}

void Info::setProbability(int p) {
   probability.push_back(p);
}

 void Info::addToTimeLocation(string s)
 {
     timeLocation.push_back(s);
 }

 void Info::addVideoName(string s)
 {
     int pos = s.rfind("/");
     //int periodPos = s.rfind(".");
      s = s.substr(pos+1);
     videoName.push_back(s);
 }

 void Info::addVideoName2(string s)
 {
     int pos = s.rfind("/");
      s = s.substr(pos+1);
     videoName2.push_back(s);
 }

 void Info::addVideoName3(string s)
 {
     int pos = s.rfind("/");
      s = s.substr(pos+1);
     videoName3.push_back(s);
 }

 bool Info::is_file_exist(string fileName)
 {
     ifstream infile(fileName);
     return infile.good();
 }

 void Info::addCharNum(string num)
 {
     characteristicNum.push_back(num);
 }

 void Info::addOrderClicks()
 {
     vector<int> start2;
     int index = 1;
     for (int j = 0; j < 8; j++) {
         for (int i = 0; i < sequencePlayed.size(); i++) {
             if (sequencePlayed.at(i).compare(std::to_string(index))==0) {
                 start2.push_back(i);
                 break;
             }
         }
         index++;
     }
     start2.push_back(sequencePlayed.size());
     vector<int> start;
     for (int i = 0; i < start2.size() - 1; i++) {
         string last = "";
         for (int j = start2.at(i); j < start2.at(i+1); j++) {
             if (timestamp.at(j).compare(last) != 0) {
                 start.push_back(j);
                 last = timestamp.at(j);
             }
         }
     }
     start.push_back(sequencePlayed.size());
     for (int i = 0; i < start.size() - 1; i++) {
         vector<qint64> timeCopy;
         vector<qint64> timeCopy2;
         for (int j = start.at(i); j < start.at(i+1); j++) {
             timeCopy.push_back(intTime.at(j));
             timeCopy2.push_back(intTime.at(j));
         }
         std::sort(timeCopy.begin(), timeCopy.end());
         vector<int> order;
         for (int k = 0; k < timeCopy2.size(); k++) {
             for (int l = 0; l < timeCopy.size(); l++) {
                 if (timeCopy2.at(k)==timeCopy.at(l)) {
                     order.push_back(l+1);
                     break;
                 }
             }
         }
         for (int m = 0; m < order.size(); m++) {
             orderOfClicks.push_back(std::to_string(order.at(m)));
         }
     }
 }

 void Info::addToSequencePlayed(string s)
 {
     sequencePlayed.push_back(s);
 }

 void Info::addToSequencePlayed2(string s)
 {
     sequencePlayed2.push_back(s);
 }

 void Info::addToSequencePlayed3(string s)
 {
     sequencePlayed3.push_back(s);
 }

  void Info::addToOrderCheckedTotal()
  {
      vector<int> start;
      int index = 1;
      for (int j = 0; j < 8; j++) {
          for (int i = 0; i < sequencePlayed.size(); i++) {
              if (sequencePlayed.at(i).compare(std::to_string(index))==0) {
                  start.push_back(i);
                  break;
              }
          }
          index++;
      }
      start.push_back(sequencePlayed.size());
      for (int i = 0; i < start.size() - 1; i++) {
          vector<qint64> timeCopy;
          vector<qint64> timeCopy2;
          for (int j = start.at(i); j < start.at(i+1); j++) {
              timeCopy.push_back(intTime.at(j));
              timeCopy2.push_back(intTime.at(j));
          }
          std::sort(timeCopy.begin(), timeCopy.end());
          vector<int> order;
          for (int k = 0; k < timeCopy2.size(); k++) {
              for (int l = 0; l < timeCopy.size(); l++) {
                  if (timeCopy2.at(k) == timeCopy.at(l)) {
                      order.push_back(l+1);
                      break;
                  }
              }
          }
          for (int m = 0; m < order.size(); m++) {
              orderCheckedTotal.push_back(std::to_string(order.at(m)));
          }
      }
  }

void Info::addBodyPartNum(string s)
  {
      bodyPartNum.push_back(s);
  }

void Info::addToRealTime1(string s) {
    realTime1.push_back(s);
}

void Info::addToRealTime2(string s) {
    realTime2.push_back(s);
}

void Info::addParticipantNum(int i) {
    participantNumber = i;
}

void Info::addToIntTime(qint64 t) {
    intTime.push_back(t);
}
