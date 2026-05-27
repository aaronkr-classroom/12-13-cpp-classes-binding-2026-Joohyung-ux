#pragma once
#ifndef GUARD_STR_H
#define GUARD_STD_H

#include <algorithm>
#include <iterator>
#include <cstring>
#include "Vec.h"

using namespace std;

class Str {
	friend istream& operator >>(istream&, Str&);
public:
	typedef Vec<char>::size_type size_type;
	typedef char* iterator;
	typedef const char* const_iterator;

	//생성자
	//1.비어 있는 Str 객체를 만드는 기본 생성자
	Str() { } // 초기값 없다

	//2. c의 복사본 n개가 있는 Str 객체를 생성
	Str(size_type n, char c) : data(n,c) { }

	//3.null로 끝나는 char 타입의 배열에서 Str 객체를 생성
	Str(const char* cp) {
		copy( //std::copy()
			cp, cp + strlen(cp), //std::strlen()
			back_inserter(data) //std::back_inserter()->역방향 삽입
		);
	}

	//4.반복자 b와 e가 가리키는 범위에서 Str 객체를 생성
	template<class ln> Str(ln b, ln e) {
		copy(b, e, back_inserter(data));
	}
	//길이/크기 함수
	size_type size() const { return data.size(); }

	//연산자 : 인덱스
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	//연산자 : 결합
	Str& operator+=(const Str& s) {
		copy(s.data.begin(), s.data.end(),
			back_inserter(data));
		return *this;
	}

	//연습문제 12:반복자들
	iterator begin() { return data.begin(); }
	iterator end() { return data.end(); }
	iterator insert(iterator d, iterator b, iterator e) {
		return data.insert(d, b, e);
	}
private:
	Vec<char> data;
};

ostream& operator<< (ostream&, const Str&);
Str operator+(const Str&, const Str&);

#endif
