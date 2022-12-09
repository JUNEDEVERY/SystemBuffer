
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>
LPWSTR ClipboardOutPutText1();
#define SIZE_BUFFER 512

int WINAPI WinMain(HINSTANCE hInstance,    // дескриптор текущего экземпляра окна 
	HINSTANCE hPrevInstance,// дескриптор предыдущего экземпляра окна
	LPSTR lpCmdLine,        // указатель на командную строку
	int nCmdShow            // показывает состояние окна

)
{
	while (TRUE) {
		LPSTR Data = ClipboardOutPutText1();
		TCHAR Alert[] = L"Вы украли этот текст: ";
		TCHAR Number[] = L"";
		TCHAR third[512]; // массив на ограничение длины символов
		swprintf(third, sizeof third, L"%s%s", Alert, Data);

		switch (*Data) {
		case '1': {

			swprintf(third, sizeof third, L"%Одын", Number, Data);
			break;
		}
		case '2': {

			swprintf(third, sizeof third, L"%Двас", Number, Data);
			break;
		}
		case '3': {

			swprintf(third, sizeof third, L"%Одын", Number, Data);
			break;
		}
		case '4': {

			swprintf(third, sizeof third, L"%Читыле", Number, Data);
			break;
		}
		case '5': {

			swprintf(third, sizeof third, L"%Пять ( файв )", Number, Data);
			break;
		}
		case '6': {

			swprintf(third, sizeof third, L"%Сикс", Number, Data);
			break;
		}
		case '7': {

			swprintf(third, sizeof third, L"%Семь", Number, Data);
			break;
		}
		case '8': {

			swprintf(third, sizeof third, L"%Восэм", Number, Data);
			break;
		case '9': {

			swprintf(third, sizeof third, L"%Дэвят", Number, Data);
			break;
		}
		case '0': {

			swprintf(third, sizeof third, L"%Нолик", Number, Data);
			break;
		}
		}
		
		}
		if (*Data != 0) { // если значение даты не равно нулю (не пустая строка)

			MessageBoxW(NULL, &third, L"Ты нарушил закон!", MB_OK | MB_ICONWARNING);
			ClipboardInputTEXT(""); // кладем пустую строку для очистки


		}
		else {};
		Sleep(1000);

	}
	return 0;

}
TCHAR* ClipboardOutPutText1() {

	TCHAR* message = NULL;
	OpenClipboard(NULL);

	HANDLE clipboardData = GetClipboardData(CF_UNICODETEXT);
	message = (TCHAR*)GlobalLock(clipboardData); // считали из глобального участка памяти, привел к строке
	GlobalUnlock(clipboardData);
	CloseClipboard();
	EmptyClipboard();
	return message;
}
int ClipboardInputTEXT(LPWSTR buffer) {


	DWORD lenghtWord;
	HANDLE hMem;
	lenghtWord = wcslen(buffer) + 1; // длина в юникоде
	hMem = GlobalAlloc(GMEM_MOVEABLE, lenghtWord * sizeof(LPWSTR)); // определение длины строки в юникоде
	memcpy(GlobalLock(hMem), buffer, lenghtWord * sizeof(LPWSTR)); // копирование области памяти из buffer в hmem
	// резервируем память чтоб другой процесс не взял

	GlobalUnlock(hMem); // для других прог
	OpenClipboard(0); // открыть буфер обмена
	EmptyClipboard(); // очистить буфер
	SetClipboardData(CF_UNICODETEXT, hMem); // запись в буфер соответствующего типа
	CloseClipboard(); // закрыли буфер
	return 100500;

}