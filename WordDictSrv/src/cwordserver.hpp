﻿//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : CWordDict
//  @ File Name : cwordserver.hpp
//  @ Date : 2015/2/10
//  @ Author : wangqunfeng
//
//


#if !defined(_CWORDSERVER_H)
#define _CWORDSERVER_H

#include <list>

#include "cworddb.hpp"
#include "eworderror.hpp"

class CWordServer
{
private:
    /**< server构造函数，为配合单例模式放入private类别下 */
    CWordServer();

public:
    /**< 获取server实例 */
    static CWordServer * Instance();
    /**< server析构 */
    virtual ~CWordServer();
    /**< 初始化server */
    EErrorCode init();

    /**< 开启服务，正常情况下函数不返回，返回进程将立即结束 */
    EErrorCode start();
    /**< 载入本地数据库 */
    EErrorCode mk_db(const std::string& path, const std::string& dbname);
    /**< 卸载数据库 */
    EErrorCode rm_db(const std::string& dbname);
    /**< 使用内存数据库更新本地数据库 */
    EErrorCode update_db(const std::string& dbname);

private:
    /**< 翻译缓冲区1的单词，并扔进缓冲区2，并发回到client */
    int translate(const char* buff1, char* buff2, unsigned int len1, unsigned int len2);

private:
    /**< 套接字描述符 */
    int m_skfd;
    /**< Epoll描述符 */
    int m_epfd;
    /**< 词典数据库保存在m_lpdb中 */
    std::list<CWordDB*> m_lpdb;

    /**< server实例，单例模式 */
    static CWordServer* _instance;
    /**< 已使用的instance引用的个数，用作智能指针 */
    static ssize_t _inst_nr;
    /**< socket数据缓冲区 */

    static char m_buff[1024];
};

#endif  //_CWORDSERVER_H