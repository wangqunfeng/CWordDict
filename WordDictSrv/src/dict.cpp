#include <iostream>
#include <string>

#include <regex>

#include "cworddb.hpp"
#include "cwordconfig.hpp"
#include "cwordserver.hpp"
#include "eworderror.hpp"

using namespace std;

int main(int argc, char **argv)
{
    EErrorCode err = E_SUCCESS;
    CWordServer* ps = CWordServer::Instance();
    err = ps->init();
    if(E_SUCCESS != err)
    {
        cout << err2str(err) << endl;
        return err;
    }
    ps->mk_db("/home/qunfeng/develop/WordDictSrv/1.txt", "basic directory");
    ps->start();
//    const std::regex pattern_word("^[1-9]\\d*,\\s(\\w+)\\s+(\\[.+\\])[\\n\\r]{0,2}$");
//    const std::regex pattern_exp("^([vnac]\\w*)\\.\\s+(.+)[\\n\\r]{0,2}$");
//    string str("1, monolithic  [mɒnə'lɪθɪk]\n");
//    string str2("adj. 整体的；巨石的，庞大的；完全统一的 \n\r");
//    std:: match_results<std::string::const_iterator> match_result;
//    if(regex_match(str, match_result, pattern_word))
//        {
//            //flush buffer before store new word&exp
//            cout << match_result[1] << "~~" << match_result[2] << endl;
//        }
//    if(regex_match(str2, match_result, pattern_exp))
//    {
//            cout << match_result[1] << "~~" << match_result[2] << endl;
//    }
//    CWordDB *p_db = new CWordDB();
//    p_db->load("d:\\1.2.txt");
//    string s2;
//
//    cout << p_db->rd_explan("evolution") << endl;
//    cout << p_db->rd_explan("approximate") << endl;
//
//    cout << "word count: " << p_db->get_dbc() << endl;
//    p_db->store("d:\\1.3.txt");
    return 0;
}
