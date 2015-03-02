﻿//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : WordDict
//  @ File Name : cworddb.hpp
//  @ Date : 2015/2/10
//  @ Author : wangqunfeng
//
//


#if !defined(_CWORDDB_H)
#define _CWORDDB_H

#include <string>
#include <list>
#include <map>

#include "eworderror.hpp"

// word database class
class CWordDB
{
public:
    CWordDB();
    CWordDB(const std::string& dbn);
    virtual ~CWordDB();
    // load db from local file
    EErrorCode load(const std::string& path);
    // store db to local file
    EErrorCode store(const std::string& path);
    // set/get db name
    void set_db_name(const std::string& dbn) { m_dbn = dbn;}
    std::string get_db_name(void) const { return m_dbn;}
    // add new pair<word, explanation> to db
    EErrorCode mk_explan(const std::string& word, const std::string& explan);
    // remove pair<word, explanation> from db
    // if explanation not specified, remove word and its all explanations from db
    EErrorCode rm_explan(const std::string& word, const std::string& explan);
    // search explanation of a certain word from db
    std::string rd_explan(const std::string& word) const;
    // get count of words in db directly returns m_dbc
    int get_dbc();

private:
    // type of db
    typedef std::map<std::string, std::list<std::string> > t_db;
    // type of constant iterator of db
    typedef std::map<std::string, std::list<std::string> >::const_iterator t_db_cit;
    // type of iterator of db
    typedef std::map<std::string, std::list<std::string> >::iterator t_db_it;
    // type of word(contains explanation of the word) in db
    typedef std::pair<std::string, std::list<std::string> > t_db_word;
    // type of explanation in db
    typedef std::list<std::string> t_db_exp;
    // type of iterator of explanation of a word in db
    typedef std::list<std::string>::iterator t_db_exp_it;
    // type of constant iterator of explanation of a word in db
    typedef std::list<std::string>::const_iterator t_db_exp_cit;

private:
    // database
    // each object of class this->class has only one database map
    t_db m_db;
    // words count of this db
    int m_dbc;

    std::string m_dbp;

    // database name, used as identifier in a system.
    std::string m_dbn;
};

#endif  //_CWORDDB_H