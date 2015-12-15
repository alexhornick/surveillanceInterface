#ifndef BODYPART_H
#define BODYPART_H
#include <QString>
#include <vector>
using namespace std;
class BodyPart
{
public:
    BodyPart(string n, string d);
    string name;
    vector<string> data;
};

#endif // BODYPART_H
