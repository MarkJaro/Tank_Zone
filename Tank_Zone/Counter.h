#pragma once
#ifndef COUNETR_H
#define COUNETR_H
static class Counter
{
public:
	static int count;

public:
	static int getId() { count++; return count; }

};
#endif