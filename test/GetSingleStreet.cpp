
#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    int seqno = 1;

    if(route.get_street_address(seqno) == 0)
    {
        cout << "Adress:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
