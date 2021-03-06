#ifndef __dchain__
#define __dchain__
/*
dchain类为同一种数据提供了链式存储方式
无论如何dchain都会拷贝一份数据,所以如果要存入
dchain的数据不能拷贝则应当存入相应的地址指针 
*/

#include "dream.h"

namespace dream{

template< typename Tpn >
class dchain {
	private:
		/***节点数据***/ 
		struct node {
			Tpn		mValue;	//保存目标数据的值 
			node	*prev;
			node	*next;		//挂载指针 
		};
	private:
		node*		mpHead;		//首节点指针 
		node*		mpTail;		//尾节点指针 
		node*		mpFocus;	//当前节点指针 
	private:
		/***寻找节点指针***/ 
		node* find( int ) const;
	public:
		/*构造函数*/
		dchain( void );
		/*析构函数将清除链中数据*/
		~dchain( void );
		
		/*在末端添加数据*/
		bool push( const Tpn& ); 
		bool push( void );
		/*在当前位置插入数据*/
		bool insert( const Tpn& );
		bool insert( void );
		/*在特定位置插入数据*/
		bool insert( const Tpn&, int );
		
		/*删除当前节点*/ 
		bool remove( void );
		/*删除某个节点*/
		bool remove( int ); 
		/*删除所有节点*/
		void clear( void ); 
		
		/*寻找某个节点*/
		bool focus( int );	//修改当前关注指针的位置 
		bool next( void );
		bool prev( void );
		Tpn* focus( void ) const;	//返回当前关注指针的内容 
		Tpn& ifocus( void ) const;//返回当前关注内容的引用 
		Tpn* at( int ) const;
		Tpn& operator[] ( int ) const;	//错误则抛出异常
		/*返回当前关注点的位置*/
		int locat( void ) const;
		bool bHead( void ) const;
		bool bTail( void ) const;
		bool bEmpty( void ) const;
		/*返回当前节点数量*/
		int count( void ) const; 
		
		/*修改内容数据*/
		bool set( const Tpn& );
		bool set( const Tpn&, int );
};

}
#endif
