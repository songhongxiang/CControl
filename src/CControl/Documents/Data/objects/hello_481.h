/*
 * hello_481.h
 *
 * Created on : 2023-11-12 17:39:40
 * Author: <Your name>
 * Purpose: <Classify <your things>
 * Model ID: 21385
 */

#ifndef hello_481_H_
#define hello_481_H_

/* Add the CControl header file */
#include "ccontrol.h"

/*
 * This is a K-nearest neighbor - A model that can classify raw data.
 * Most used for descriptors, but you can use it at any data you want as long the data is stored into .pgm files in format P2 or P5.
 * This file contains one vector called 'hello_481_N'.
 * To use this header file, your data that must be a vector of size 'hello_481_N'
 * For example, if you have an descriptors with length m, where m = 'hello_481_N', then you can XOR-multiply the data with your data.
 * The smallest number is the class ID
 */

#define hello_481_N 481

const static uint64_t hello_481_w[hello_481_N] = { 0x3FFE7FFE, 
0xF3E3FBF9, 
0x3FFC3FFE, 
0x787E7E7F, 
0x3FFE7FFE, 
0xFFFFFFFF, 
0xFFFBFEF3, 
0xFF3FFFE3, 
0x831BE73D, 
0xFFF3FFF7, 
0xE3E7FB83, 
0xF9DFF9DF, 
0xFFFFFFFF, 
0xFFFCF7F8, 
0x7FFEFFFF, 
0xF8D8D088, 
0xBF7FFF7F, 
0x1CFE0FFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFE7FFE7, 
0xFEF8FEFC, 
0x1DFC1CFE, 
0xFFF8FFFD, 
0x7FF8FFFC, 
0x7FFC7FFC, 
0xFFF0FFFC, 
0x1CFC1CFC, 
0x7F7C7F7C, 
0x3FFC7FFC, 
0x7FFC7FFC, 
0x7FF87FFA, 
0xFFF9FFF9, 
0xFFF9FFFD, 
0x7FF97FF9, 
0xFFF1FFFD, 
0x7FF87FF8, 
0xFFF1FFF9, 
0x7FFC7FFC, 
0x3FF83FF8, 
0xFFFFFFFF, 
0x7FFC7FFE, 
0x7F607FF0, 
0x7F18FDF0, 
0xFFF1FFE1, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0x7FFC7FF8, 
0x7FF83FF8, 
0x1FFC3FFE, 
0x3DFFFDFF, 
0xFFFCFFFE, 
0xFEFFFEFF, 
0xFEFFFFFF, 
0x19F819D8, 
0xFFFFFFFF, 
0x7FF83FB8, 
0x7FF3FFF2, 
0x1DFC19F8, 
0xFFFEFFFE, 
0xFFFFFFFF, 
0xFFCF7FEF, 
0xDFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xF71FC3DF, 
0xFFFFFFFF, 
0xFFFEFFFE, 
0x3FFF7FFF, 
0x10160006, 
0xE7FFFFFF, 
0xFFFFFFFF, 
0x32372327, 
0xFFF9FFFD, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0x7EFE7EFE, 
0xFFFFFFFF, 
0xFF7FFDFF, 
0xFFFFFFDF, 
0xB33FB377, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFBFFF7FF, 
0x67FEE63E, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0x1D183014, 
0x3F3F773F, 
0xFFFFFFFF, 
0xFFFFFBFF, 
0xFFFCFFFC, 
0x7FFC7FF8, 
0xFFFDFFFF, 
0xFFFEFFFE, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xC1810040, 
0xFFF8FFFC, 
0x7FF07FF0, 
0xFFF1FFF8, 
0x7FFC7FFC, 
0xFFF37FF3, 
0x7FFF7FFF, 
0x7FFE3FFE, 
0x3FB63FB6, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFCFCCCFC, 
0x7FFC7FFC, 
0x7FF83FFC, 
0x7FF87FF8, 
0x7FF87FF8, 
0xFFF0FFF0, 
0xFFFE7FFE, 
0xFFFCFFFC, 
0x7FFC7FFC, 
0x7FFE7FFE, 
0x7FFCFFFC, 
0xFFC7FFFF, 
0xFFE7FFFF, 
0xFFE3FFE3, 
0xFFFFFFFF, 
0xF3C7E1C7, 
0x38000000, 
0xFBC7FBC7, 
0xFBC3F9C1, 
0xF3C1F1C3, 
0x7FFC3FFC, 
0x99F899F8, 
0x0, 
0x2F7E7F7E, 
0x8080800, 
0x0, 
0xC1F8D8F8, 
0xFFFFFFFF, 
0xF9F9DFD9, 
0x8FFF8F7F, 
0xE1F9C9FA, 
0xFFFFFFFF, 
0xEBD9FBD9, 
0xFFE1FFF0, 
0xFFFFFFFF, 
0x8000000, 
0x2FFE7F7E, 
0x8080000, 
0xF7F8F7F, 
0x8480808, 
0x1F7E0F7E, 
0x8080000, 
0x877F8F7F, 
0xE1F8D8FC, 
0xFFFFFFFF, 
0xE1F9FBD8, 
0xCFFFCF7F, 
0xE1F9ECFF, 
0xFFFFFFFF, 
0xFFF1FFE3, 
0xE1C8F9D8, 
0xFFFFFFFF, 
0xF7FFEFFF, 
0xFFFF7F7F, 
0xC7FFC5BF, 
0xFFFFFFFF, 
0x8180800, 
0x2F7E7F7E, 
0x7FFF7FFE, 
0x8080800, 
0xF7E3F7E, 
0xE1C18181, 
0x7FFF7FFE, 
0x8480848, 
0x8080000, 
0x7FFC3FFC, 
0xFFFC7FFC, 
0x3FFF3FFF, 
0xFBC7FBC7, 
0xEF7FEFFF, 
0xFFF8FFF8, 
0x8F7F8F7F, 
0xFFF0EFE, 
0xFBCFFBEF, 
0x8F9F1F1F, 
0xFFFFF7FF, 
0x1FFE1FFF, 
0x9FFFDFFF, 
0xFFFFFFFF, 
0xFFF07FF0, 
0xFFFFFFFF, 
0xFF7CFEFE, 
0x7E3F7EFC, 
0xFFFFFFFF, 
0xF1F3F1C3, 
0xFEFFFFFF, 
0xFFF8FFF8, 
0xFFF8FFF, 
0xFFFFFFFF, 
0xCFFFCFFF, 
0x8FFF8FFF, 
0xFFE3FFE3, 
0xFFB6FDF4, 
0xE3FFEFFF, 
0xFFFFFFFF, 
0xFFF0FFF0, 
0xFEE07E60, 
0x7F707F70, 
0xE7E0E7E, 
0xFFF8FFF8, 
0xFFF8FFF8, 
0x1EFC0C7C, 
0xFFF3FFF8, 
0xFFFFFFFF, 
0x7FFC7FFC, 
0xFEF0FEE0, 
0x7FF87FF0, 
0xFFFFFFFF, 
0xFFF8FFF8, 
0xFFFFFFFF, 
0x7E383E7E, 
0xF0492808, 
0xFFF0FEF0, 
0xFDF1F9E1, 
0xFF0DFF09, 
0xFFE1FFE0, 
0xFEEFFFEB, 
0x78780848, 
0x7E407EE4, 
0xFFFFFFFF, 
0x7E59AF49, 
0xFFE7FFE7, 
0xFFE3FFF3, 
0x47400F4A, 
0x7CE0FCE0, 
0x83878B87, 
0xFFFFFFFF, 
0x3FFE3FFE, 
0xFFFBFEFF, 
0xFFFFFFFF, 
0xFEF3FFF7, 
0xFEFFFFFF, 
0xEECFCFCF, 
0xFFFFFFFF, 
0xEF6FAF27, 
0xFFEFFFFF, 
0xFFE7FFE7, 
0xFFFFFFFF, 
0xDF8FC70F, 
0xFFEFFFEF, 
0xE1C1C181, 
0xFDE1FDE1, 
0x9FFF1FFF, 
0xE0E1E1E0, 
0xFFE1FDE1, 
0x4FEF0F49, 
0xE999E989, 
0x9FFF1FFE, 
0xF1CBF9CB, 
0xFFF0FFF0, 
0xFFE1FFF1, 
0xFFF1FFF9, 
0xFFE3FFE1, 
0xFFE1FFE3, 
0xFFF7FFE3, 
0xFFE1FFE3, 
0xFDE3FDE3, 
0xFFE3FFE3, 
0x3FFE3FFE, 
0x3FFC3FFC, 
0x3FFE3FFE, 
0x1FFE3FFE, 
0xFFF8FFF8, 
0xFFFCFFFC, 
0x7FFC7FFC, 
0x83830000, 
0xC74043C, 
0xC7E8FBF8, 
0xC040404, 
0xFFFCFFFE, 
0xFFF0FFF8, 
0x3FFC3FFC, 
0x1F9E1F92, 
0xF7F0F7B0, 
0xFFF0FFF8, 
0x3FFC3FFE, 
0x1FFF1FFF, 
0x3FFE3FFE, 
0xFFF0F7F0, 
0xF7F0F7F0, 
0x7FFE7FFE, 
0xFFF0FFF0, 
0x9FFFBFFF, 
0xFFF0FFF8, 
0xFFF0FFF0, 
0xF7F0F3B0, 
0xEFFFFFFF, 
0xFFF0FFF0, 
0x1FFF1FFF, 
0xFFFEFFFE, 
0x1000000, 
0xE3FFEFFF, 
0xFFF0FFF8, 
0x8FFF0FFF, 
0xEFFFFFFF, 
0xE0200000, 
0x1FFF1FFF, 
0xFFEFFFEF, 
0x671FE6FE, 
0xFEE0E6E0, 
0xEFFFEFFF, 
0xCFFF8FFF, 
0x7F037CC0, 
0xFFF0FFF, 
0xFFE1FFF1, 
0xC0F08034, 
0xFFFFFFE6, 
0x3C7E0EFE, 
0xFFF0FFF0, 
0xFFE1FFF0, 
0x3CFC0EFE, 
0xFFFFFFFE, 
0x7FFE7FFE, 
0x7FF87FF8, 
0x7FFC7FFC, 
0x3DFC7FFE, 
0xA1111101, 
0xFFF1FFF3, 
0xFFFFFFFF, 
0xF7F1B7B1, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xE3E38303, 
0xFFE7EFE7, 
0xFFEFFFEF, 
0xFFFFFFFF, 
0xE1A10101, 
0xFFF3FFF7, 
0xE7FFEFFF, 
0xEFFFEFFF, 
0xE1878107, 
0xEFFFFFFF, 
0x7E707C60, 
0x7FF07FF0, 
0xFFF1FFF8, 
0x7FFC7FFC, 
0xFFF37FF3, 
0x7FFF7FFF, 
0x7FFE3FFE, 
0x3FB63FB6, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xCFFFFFFF, 
0xDFFFFFFF, 
0xC3FFCFFF, 
0xFFFFFFFF, 
0xFEFEFEFF, 
0xFFFFFFFF, 
0xF9E3F9E3, 
0xFDE1FFE0, 
0x3C7C7CFC, 
0xFFF1FFF0, 
0xFFF07F70, 
0x79F879D0, 
0x7FE8FFFC, 
0x7FF8FFF8, 
0x78E07040, 
0x7FF07DF0, 
0xFEF87E7C, 
0x3FFC3FFC, 
0x7F703F30, 
0x7FF0FFF0, 
0x7FFCFFFE, 
0xFFF0FFF0, 
0xBFFFBFFF, 
0xFFF07FF0, 
0xFFF1FFF1, 
0xFFF9BFFC, 
0xFFFEFFFE, 
0x1FFF3FFF, 
0xFFF1FFF1, 
0x1FFF3FFF, 
0x9FFF8FFF, 
0xBBDB9BDB, 
0xFBF1F7F7, 
0xFFE1FFE0, 
0xC3879397, 
0xE3C7F3F7, 
0xFFFFFFFF, 
0xFEE1FFE1, 
0x1FFF1FFF, 
0xFFFFFFFF, 
0xBFFF3FDF, 
0x1FFF0FFF, 
0xFFF1FFE3, 
0xFFF1FFF, 
0x73F0F1F, 
0x87878307, 
0xE2E10701, 
0x1FFF0FFF, 
0xFFF3FFE3, 
0xFFF0FFE, 
0xFFFFFFFF, 
0xEFE0EFE, 
0x1FFE1FFE, 
0xF8B81100, 
0xFFE1FFE, 
0x1FFF1FFF, 
0xFFFFFFFF, 
0x3FDF1FDF, 
0xF0E0F0C0, 
0x1FFF0FFF, 
0x8FFF0FFF, 
0xF7E0F7D0, 
0xFEF07C70, 
0xFFF7FFFF, 
0x3C383030, 
0xF6F1F1F0, 
0xFFB9FFF1, 
0xFFFFFFFF, 
0xBFFFBFFF, 
0xFFF1FFF, 
0xFFEFFFF7, 
0x8FFF0E3E, 
0xEEBEE5BD, 
0xE1B1E4B4, 
0xFDFFFCFC, 
0x3C7C3EFC, 
0x1FFF0FFF, 
0xFFF87FFC, 
0x7FFC7FFC, 
0x3F0F0F0B, 
0x3FFC7FFE, 
0xFFF0FFF8, 
0x7FE0FFF0, 
0x7FF8FFF0, 
0x7F70FFF0, 
0xFFF87FF8, 
0xEF90FFB0, 
0x7FF8FFF8, 
0x7FFC7FFC, 
0xF7E8F7F0, 
0xFFFCFFFD, 
0xFFF0FFF0, 
0xFFF3FFF1, 
0xFFFFFFFF, 
0x1FFE1FFE, 
0x97FF9FFF, 
0xFFFFFFFF, 
0xCF3FDFFF, 
0x7F47FFF7, 
0xC3878307, 
0xFDFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xE707E090, 
0x3F3F7F7E, 
0xE8882080, 
0xF8F870E0, 
0x3FFC3FFC, 
0x7FF87FFC, 
0xDFF9FFFB, 
0x7FF87FFC, 
0xBFFFBFFF, 
0x1FFE3FFE, 
0x7FF8FFF0, 
0x83FF0FFF, 
0x1FFF3FFE, 
0x1FFF1FFE, 
0xD1C0C0C0, 
0x7FE1FFE, 
0x4040404, 
0x7F07FFE3, 
0x2000000, 
0xFDF0FDE0, 
0x1FFE1FFE, 
0xFFF0FFF0, 
0xFFC0FEE0 };

#endif /* !hello_481_H_ */
