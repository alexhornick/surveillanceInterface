#include "bodypart.h"
using namespace std;
BodyPart::BodyPart(string n, string d)
{
    name = n;
    while(d.find(",")!= -1) {
        data.push_back(d.substr(0, d.find(",")));
        d = d.substr(d.find(",") + 2, d.size() - d.find(",") - 2);
    }
    data.push_back(d);
}
