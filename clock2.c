#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
//global variable declaration
int choice;

VOID WINAPI Sleep( //sleep function
    _In_ DWORD dwMilliseconds);

int currenttime() //function that print the current time
{
    // time_t t;
    // time(&t);
    // printf("%s", ctime(&t));
    time_t rawtime;
    struct tm *timeinfo;

    // Used to store the time
    // returned by localetime() function
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80,
             "Time is %I:%M%p.",
             timeinfo);
    puts(buffer);

    return 0;
}

int setTime()
{ // function that takes input and displays the given time
    int hour, min, sec, d = 1000;

    printf("\n .............Set time .................:\n");
    printf("Enter the new time : (format in 00:00:00) ");
    scanf("%d%d%d", &hour, &min, &sec);

    if (hour > 12 || min > 60 || sec > 60)
    {
        printf("Enter the input in 12-hour format: ");
        scanf("%d%d%d", &hour, &min, &sec);

        //exit(0);
    }
    for (;;) // this loop runs for the infinty number of times
    {
        sec++;
        if (sec > 59)
        {
            min++;
            sec = 0;
        }
        if (min > 59)
        {
            hour++;
            min = 0;
        }
        if (hour > 12)
        {
            hour = 1;
        }
        printf("%02d:%02d:%02d", hour, min, sec);
        Sleep(d); // waits for 1000 milli seconds
        system("cls");
    }
}

void sound()
{
    //     int time;
    //     time = 1*120;
    //   Beep(500,time);
    // int i;
    //   for(i=0;i<10;i++){
    //    Beep(1000, 300);}
    //    return 0;

    int x;

    // Loop for sound Jingle
    for (x = 0; x < 2; x++)
    {
        Beep(523, 500);
    }

    // sound Bell
    Beep(523, 800);

    Sleep(200);

    // Loop for sound Jingle
    for (x = 0; x < 2; x++)
    {
        Beep(523, 500);
    }

    // sound Bell
    Beep(523, 800);

    // Sound for rest of the tone
    Sleep(200);

    Beep(523, 500);

    Sleep(50);

    Beep(659, 400);

    Sleep(50);

    Beep(440, 400);

    Sleep(50);

    Beep(494, 400);

    Sleep(50);

    Beep(523, 750);

    Sleep(400);

    Beep(600, 400);

    Sleep(100);

    Beep(600, 350);

    Sleep(200);

    Beep(600, 300);

    Sleep(150);

    Beep(600, 250);

    Sleep(150);

    Beep(600, 150);

    Sleep(150);

    Beep(550, 250);

    Sleep(150);

    Beep(555, 350);

    Sleep(50);

    Beep(555, 200);
    Sleep(150);

    Beep(555, 200);

    Sleep(150);

    Beep(690, 200);

    Sleep(150);

    Beep(690, 200);

    Sleep(150);

    Beep(610, 200);

    Sleep(150);

    Beep(535, 160);

    Sleep(100);

    Beep(500, 150);

    Beep(500, 50);

    Sleep(200);

    Beep(700, 200);
}

int minutes()
{

    int d = 1000;

    int i;

    int minutes, temp;

    printf("Enter the time in minutes : ");

    scanf("%d", &minutes);
    temp = minutes * 60;

    for (i = temp; i >= 0; i--)
    {
        system("cls");
        printf("Remaining time is %d seconds\n", i);
        Sleep(d);
    }
    printf("The time is up !!");
    // Function that beeps a sound of
    // frequency 750 for 0.8 sec
    sound();
    return 0;
}

int seconds()
{
    int seconds;
    int d = 1000;
    int i;
    printf("Enter the time in seconds : ");
    scanf("%d", &seconds);
    // temp = minutes * 60;
    for (i = seconds; i >= 0; i--)
    {
        system("cls");
        printf("Remaining time is %d seconds\n", i);
        Sleep(d);
    }
    printf("The time is up !!");
    // Function that beeps a sound of
    // frequency 750 for 0.8 sec
    sound();
}

int counter()
{
    int select;
    int d = 1000;
    int i;

    printf("Enter the time in : \n 1.minute format . \n 2.seconds format \n Enter your option : ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        minutes();
        break;

    case 2:
        seconds();
        break;
    case 3:
        printf("The number you entered is done !! please recheck the number you entered !!!");
    }
}

void main()
{
repeat:
    printf("\n ...................Clock..................... \n");
    printf("\n");
    printf("Choose the option from below : \n 1.Show current time . \n 2.Set time .\n 3.counter : \nEnter the option : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        currenttime();
        // exit(0);
        break;
    case 2:
        setTime();
        break;
    case 3:
        counter();
        break;

    default:
        printf("\nEnter the correct input !! Wrong input\n");
        goto repeat;
    }
}