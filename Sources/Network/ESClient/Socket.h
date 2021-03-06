/********************************************************************
	created:	2003/02/14
	file base:	Socket
	file ext:	h
	author:		liupeng
	
	purpose:	
*********************************************************************/
#ifndef __INCLUDE_SOCKET_H__
#define __INCLUDE_SOCKET_H__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
	#pragma once
#endif

#include <winsock2.h>

#include "Win32Exception.h"
#include "tstring.h"

/*
 * namespace OnlineGameLib::Win32
 */

namespace OnlineGameLib {
namespace Win32 {

/*
 * CSocket
 */
class CSocket  
{
public:
	
	class InternetAddress;
	class Exception;
	
	CSocket();	
	explicit CSocket( SOCKET theSocket );
	
	~CSocket();
	
	void Attach( SOCKET theSocket );	
	SOCKET Detatch();
	
	void Close();	
	void AbortiveClose();
	
	void Shutdown( int how );
	
	void Connect( const SOCKADDR_IN &address );	
	void Connect( const struct sockaddr &address, size_t addressLength );
	
private:
	
	SOCKET m_socket;
	
	/*
	 * No copies do not implement
	 */
	CSocket( const CSocket &rhs );
	CSocket &operator=( const CSocket &rhs );
};

/*
 * CSocket::InternetAddress
 */
class CSocket::InternetAddress : public SOCKADDR_IN
{
public:
	
	InternetAddress( 
				const _tstring &addressToConnectServer,
				unsigned short port );
};

/*
 * CSocket::Exception
 */
class CSocket::Exception : public CWin32Exception
{
	friend class CSocket;
	
private:
	
	Exception( const _tstring &where, DWORD error );
};

} // End of namespace OnlineGameLib
} // End of namespace Win32

#endif //__INCLUDE_SOCKET_H__