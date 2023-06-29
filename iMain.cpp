#include "iGraphics.h"
#include <stdio.h>
#include <windows.h>
#include <Mmsystem.h>
#define ULx 1920
#define LLx 0
#define ULy 1080
#define LLy 0
#define r 48
#define le 540
#define ue 810
#define tiles_at_a_time 3
#define id 4
#define no_of_tracks 5
int no_of_lives = 1;
double vel = 2;
double dx = 50;
double dy = 200;
double dx1 = 1300, dy1 = 100;
double direc = 1;
int int_score = 0;
int lives = no_of_lives;
int timer = 90;
int dup_timer = 90;
int o = 4;
int showtimer[10] = {9, 0};
int N = 2;
int M = 1;
bool m = true;
int dup_lives = no_of_lives;
char live[20][10] = {"heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp", "heart.bmp"};
float n = no_of_tracks;
double xrand[no_of_tracks][4] = {{540}, {708}, {876}}, yrand[no_of_tracks][4] = {{810, 0, 0, 0}, {810, 0, 0, 0}, {810, 0, 0, 0}}; //////
double length_1[no_of_tracks] = {250, 250, 250, 250, 250};
double resume_vel = 1;
char score_img[10][20] = {"0_num.bmp", "1_num.bmp", "2_num.bmp", "3_num.bmp", "4_num.bmp", "5_num.bmp", "6_num.bmp", "7_num.bmp", "8_num.bmp", "9_num.bmp"};
char score_img2[10][20] = {"0_n.bmp", "1_n.bmp", "2_n.bmp", "3_n.bmp", "4_n.bmp", "5_n.bmp", "6_n.bmp", "7_n.bmp", "8_n.bmp", "9_n.bmp"};
int no_of_dig = 0;
int no_of_dig_high = 0;
int number[30];
int number_high[30];
bool flag[30] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
int reset[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int speed[30] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int i = 0;
double vel_capture = 2;
bool timer_pos = true;
bool speedhalf = false;
bool speedfull = false;
bool speeddouble = false;
bool live5 = false;
bool live10 = false;
bool live15 = false;
bool tiles_timed_out[7] = {false, false, false, false, false, false, false};
bool musicon = true;
bool music_pop = true;
bool menu = true;
bool pause = false;
bool resume = false;
bool retry = false;
bool high_score = false;
bool startgamemode_0 = false;
bool startgamemode_1 = false;
bool startgamemode_2 = false;
bool startgamemode_3 = false;
bool settings = false;
int time_counter_cloud = 0;
int time_counter = 0;
char rick[60][15] = {"rick\\0001.bmp", "rick\\0002.bmp", "rick\\0003.bmp", "rick\\0004.bmp", "rick\\0005.bmp", "rick\\0006.bmp", "rick\\0007.bmp", "rick\\0008.bmp", "rick\\0009.bmp", "rick\\0010.bmp", "rick\\0011.bmp", "rick\\0012.bmp", "rick\\0013.bmp", "rick\\0014.bmp", "rick\\0015.bmp", "rick\\0016.bmp", "rick\\0017.bmp", "rick\\0018.bmp", "rick\\0019.bmp", "rick\\0020.bmp", "rick\\0021.bmp", "rick\\0022.bmp", "rick\\0023.bmp", "rick\\0024.bmp", "rick\\0025.bmp", "rick\\0026.bmp", "rick\\0027.bmp", "rick\\0028.bmp", "rick\\0029.bmp", "rick\\0030.bmp", "rick\\0031.bmp", "rick\\0032.bmp", "rick\\0033.bmp", "rick\\0034.bmp", "rick\\0035.bmp", "rick\\0036.bmp", "rick\\0037.bmp", "rick\\0038.bmp", "rick\\0039.bmp", "rick\\0040.bmp", "rick\\0041.bmp", "rick\\0042.bmp", "rick\\0043.bmp", "rick\\0044.bmp", "rick\\0045.bmp", "rick\\0046.bmp", "rick\\0047.bmp", "rick\\0048.bmp", "rick\\0049.bmp", "rick\\0050.bmp", "rick\\0051.bmp", "rick\\0052.bmp", "rick\\0053.bmp"};
int ricki = 0;
char menuu[2][10] = {"menu.bmp", "menu2.bmp"};
int menui = 0;
char dev[5][10] = {"p1.bmp", "p2.bmp", "p3.bmp", "p4.bmp", "p5.bmp"};
int devi = 0;
char scoreliteral[10][10] = {"s.bmp", "c.bmp", "o.bmp", "r.bmp", "e.bmp"};
char score[10] = {0};



void tiles_run(int i, int speed)
{

    double t = atan(ue / (le - ((2 * le * i) / n)));

    if (i < floor(n / 2))
    {
        xrand[i][1] = length_1[i] * cos(t) + xrand[i][0];
        yrand[i][1] = length_1[i] * sin(t) + yrand[i][0];
    }
    else if (i == floor(n / 2) && ((n / 2) - floor(n / 2)) > 0.001)
    {
        xrand[i][1] = length_1[i] * cos(t) + xrand[i][0];
        yrand[i][1] = length_1[i] + yrand[i][0];
    }
    else if (i == floor(n / 2) && ((n / 2) - floor(n / 2)) < 0.001)
    {
        xrand[i][1] = -length_1[i] * cos(t) + xrand[i][0];
        yrand[i][1] = length_1[i] * sin(t) + yrand[i][0];
    }
    else
    {
        xrand[i][1] = -length_1[i] * cos(t) + xrand[i][0];
        yrand[i][1] = -length_1[i] * sin(t) + yrand[i][0];
    }
    double cont = -(((2 * le) * (i + 1)) / n) + le;
    xrand[i][2] = ((cont * (yrand[i][1])) / ue) + (((i + 1) * 1920)) / n;
    yrand[i][2] = yrand[i][1];
    xrand[i][3] = (((cont * (yrand[i][0])) / ue) + (((i + 1) * 1920) / n));
    yrand[i][3] = yrand[i][0];

    iFilledPolygon(xrand[i], yrand[i], 4);
    if (m)
    {
        iSetColor(0, 0, 0);
    }
    else
    {
        iSetColor(255, 255, 255);
    }
    iPolygon(xrand[i], yrand[i], 4);
    if (yrand[i][0] <= -300 && yrand[i][0] >= -980)
    {
        lives--; // here when lives decrease images decrease so idraw execution time decreases so the tiles speed increases. LOL some how it worked in favour of mine :)
        if (lives == 0)
        {
            if (startgamemode_0)
            {
                FILE *ftp = fopen("high_score.txt", "a");
                fprintf(ftp, "%d\n", int_score);
                fclose(ftp);
                FILE *fhigh = fopen("high_score.txt", "r");
                int score = 0;
                int max = 0;
                while (fscanf(ftp, "%d\n", &score) != EOF)
                {
                    if (score > max)
                    {
                        max = score;
                    }
                }

                int temp = int_score;
                int temp2 = int_score;

                while (temp != 0)
                {
                    temp /= 10;
                    no_of_dig++;
                }
                int i = 1;
                while (temp2 != 0)
                {
                    number[no_of_dig - i] = temp2 % 10;
                    temp2 /= 10;
                    i++;
                }
                if (no_of_dig == 0)
                {
                    number[0] = 0;
                    no_of_dig = 1;
                }

                int temp3 = max;
                int temp4 = max;

                while (temp3 != 0)
                {
                    temp3 /= 10;
                    no_of_dig_high++;
                }
                int j = 1;
                while (temp4 != 0)
                {
                    number_high[no_of_dig_high - j] = temp4 % 10;
                    temp4 /= 10;
                    j++;
                }
                if (no_of_dig_high == 0)
                {
                    number_high[0] = 0;
                    no_of_dig_high = 1;
                }
                fclose(ftp);
            }

            if (startgamemode_1)
            {
                FILE *ftp = fopen("high_score1.txt", "a");
                fprintf(ftp, "%d\n", int_score);
                fclose(ftp);
                FILE *fhigh = fopen("high_score1.txt", "r");
                int score = 0;
                int max = 0;
                while (fscanf(ftp, "%d\n", &score) != EOF)
                {
                    if (score > max)
                    {
                        max = score;
                    }
                }

                int temp = int_score;
                int temp2 = int_score;

                while (temp != 0)
                {
                    temp /= 10;
                    no_of_dig++;
                }
                int i = 1;
                while (temp2 != 0)
                {
                    number[no_of_dig - i] = temp2 % 10;
                    temp2 /= 10;
                    i++;
                }
                if (no_of_dig == 0)
                {
                    number[0] = 0;
                    no_of_dig = 1;
                }

                int temp3 = max;
                int temp4 = max;

                while (temp3 != 0)
                {
                    temp3 /= 10;
                    no_of_dig_high++;
                }
                int j = 1;
                while (temp4 != 0)
                {
                    number_high[no_of_dig_high - j] = temp4 % 10;
                    temp4 /= 10;
                    j++;
                }
                if (no_of_dig_high == 0)
                {
                    number_high[0] = 0;
                    no_of_dig_high = 1;
                }
                fclose(ftp);
            }
            PlaySound("minecraft.wav", NULL, SND_ASYNC);
            retry = true;
        }
        tiles_timed_out[i] = true;
    }
    xrand[i][0] -= vel / tan(t) * speed * 12 * resume_vel; // 10 is kay?
    yrand[i][0] -= vel * speed * 12 * resume_vel;
    dx += direc * 1; // cloud speed
    dx1 += (-direc * 0.5);
}




void iDraw()
{ // IDRAW changes time to update when i use many ishowbmp

    iClear();
    printf("\n new draw\n");
    if (menu)
    {

        iShowBMP(0, 0, "back2.bmp");
        iShowBMP2(dx, dy, "floating1.bmp", 0);
        iShowBMP2(dx + 800, dy + 70, "floating1.bmp", 0);
        iShowBMP2(0, 0, menuu[menui], 255);
        iShowBMP2(400, 753, dev[devi], 255);
        dx += direc * 1.5; // cloud speed
        if (dx < 10 || dx > 1200)
        {
            direc *= (-1);
        }
    }
    if (high_score)
    {
        iShowBMP(0, 0, "back.bmp");
        FILE *fhigh = fopen("high_score.txt", "r");
        int score = 0;
        int max = 0;
        while (fscanf(fhigh, "%d\n", &score) != EOF)
        {
            if (score > max)
            {
                max = score;
            }
        }
        int temp3 = max;
        int temp4 = max;
        no_of_dig_high = 0;
        while (temp3 != 0)
        {
            temp3 /= 10;
            no_of_dig_high++;
        }
        int j = 1;
        while (temp4 != 0)
        {
            number_high[no_of_dig_high - j] = temp4 % 10;
            temp4 /= 10;
            j++;
        }
        if (no_of_dig_high == 0)
        {
            number_high[0] = 0;
            no_of_dig_high = 1;
        }
        fclose(fhigh);
        iShowBMP2(0, 0, "high_score.bmp", 255);
        for (int i = 0; i < no_of_dig_high; i++)
        {
            iShowBMP2(1085 + i * 50, 629, score_img[number_high[i]], 255);
        }

        FILE *fhigh1 = fopen("high_score1.txt", "r");
        int score1 = 0;
        int max1 = 0;
        while (fscanf(fhigh1, "%d\n", &score1) != EOF)
        {
            if (score1 > max1)
            {
                max1 = score1;
            }
        }

        int temp31 = max1;
        int temp41 = max1;
        no_of_dig_high = 0;
        while (temp31 != 0)
        {
            temp31 /= 10;
            no_of_dig_high++;
        }
        int j1 = 1;
        while (temp41 != 0)
        {
            number_high[no_of_dig_high - j1] = temp41 % 10;
            temp41 /= 10;
            j1++;
        }
        if (no_of_dig_high == 0)
        {
            number_high[0] = 0;
            no_of_dig_high = 1;
        }
        fclose(fhigh1);

        for (int i = 0; i < no_of_dig_high; i++)
        {
            iShowBMP2(1088 + i * 50, 440, score_img[number_high[i]], 255);
        }
        iShowBMP2(1320, 760, "steve.bmp", 255);
    }
    if (settings)
    {
        iShowBMP(0, 0, "back.bmp");
        iShowBMP2(0, 0, "settings.bmp", 255);
        if (speedhalf)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(690, 600, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(690, 600, 45, 45);
        }
        if (speedfull)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(1160, 600, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(1160, 600, 45, 45);
        }
        if (speeddouble)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(1650, 600, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(1650, 600, 45, 45);
        }
        if (live5)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(690, 175, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(690, 175, 45, 45);
        }
        if (live10)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(1160, 175, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(1160, 175, 45, 45);
        }
        if (live15)
        {
            iSetColor(206, 242, 179);
            iFilledRectangle(1650, 175, 45, 45);
            iSetColor(0, 0, 0);
            iRectangle(1650, 175, 45, 45);
        }
    }

    if (startgamemode_0)
    {
        iShowBMP(0, 0, "back.bmp");
        iShowBMP2(0, 0, "cloudsdown.bmp", 0);
        iShowBMP2(dx, dy, "floating1.bmp", 0);
        iShowBMP2(dx + 700, dy + 100, "floating3.bmp", 0);
        iShowBMP2(dx1, dy1, "floating2.bmp", 0);
        iShowBMP2(dx1 - 900, dy1 - 50, "floating4.bmp", 0);

        if (dx < 10 || dx > 700)
        {
            direc *= (-1);
        }
        for (int l = 0; l < tiles_at_a_time; l++)
        {
            iSetColor(241, 194, 219); // 253, 198, 195
            tiles_run(reset[l], speed[reset[l]]);
            printf("%d\n", speed[reset[l]]);
            printf("%lf\n", yrand[reset[l]][1]);

            if (tiles_timed_out[reset[2]] == true)
            {
                yrand[reset[2]][0] = -1210;
                printf("i am here");
                time_counter = 90;
                tiles_timed_out[reset[2]] = false;
            }
            else if (tiles_timed_out[reset[l]] == true)
            {
                printf("went inside");
                yrand[reset[l]][0] = -1210;
                speed[reset[l]] = 0;
                speed[reset[l + 1]] = 1;
                printf("%d %d", l, reset[l + 1]);
                tiles_timed_out[reset[l]] = false;
            }
            if (resume)
            {
                iResumeTimer(0);
                resume_vel = 1;
            }
        }
        printf("\n\n");
        iShowBMP2(0, 0, "cloudsup.bmp", 0);
        iSetColor(0, 0, 0);
        for (int i = 0; i < 5; i++)
        {
            iShowBMP2(50 + i * 40, 900, scoreliteral[i], 0);
        }

        for (int i = 0; i < M; i++)
        {
            iShowBMP2(267 + i * 40, 900, score_img2[score[i]], 0);
        }

        for (int i = 0; i < N; i++)
        {
            iShowBMP2(50 + (dup_lives)*55 + i * 40 + 100, 980, score_img2[showtimer[i]], 0);
        }
        int i;
        for (i = 0; i < lives; i++)
        {
            iShowBMP2(50 + i * 55, 980, live[i], 0);
        }
        iShowBMP2(50 + (dup_lives)*55 + 40, 980, "clock.bmp", 0);
    }

    if (pause)
    {
        iPauseTimer(0);
        resume_vel = 0;
        iShowBMP2(0, 0, "pause.bmp", 255);
    }

    if (startgamemode_1)
    {
        if (m)
        {
            iShowBMP(0, 0, "back.bmp");
            iShowBMP2(0, 0, "cloudsdown.bmp", 0);
            iShowBMP2(dx, dy, "floating1.bmp", 0);
            iShowBMP2(dx + 700, dy + 100, "floating3.bmp", 0);
            iShowBMP2(dx1, dy1, "floating2.bmp", 0);
            iShowBMP2(dx1 - 900, dy1 - 50, "floating4.bmp", 0);
        }
        else
        {
            iShowBMP(0, 0, "back3.bmp");

            iShowBMP2(dx, dy, "floating11.bmp", 0);
            iShowBMP2(dx + 700, dy + 100, "floating11.bmp", 0);
            iShowBMP2(dx1, dy1, "floating11.bmp", 0);
            iShowBMP2(dx1 - 900, dy1 - 50, "floating11.bmp", 0);
        }
        if (dx < 10 || dx > 700)
        {
            direc *= (-1);
        }

        for (int l = 0; l < tiles_at_a_time; l++)
        {
            if (m)
            {
                iSetColor(241, 194, 219);
            }
            else
            {
                iSetColor(118, 156, 232);
            }

            tiles_run(reset[l], speed[reset[l]]);
            printf("%d\n", speed[reset[l]]);
            printf("%lf\n", yrand[reset[l]][1]);

            if (tiles_timed_out[reset[2]] == true)
            {
                yrand[reset[2]][0] = -1210;
                printf("i am here");
                time_counter = 90;
                tiles_timed_out[reset[2]] = false;
            }
            else if (tiles_timed_out[reset[l]] == true)
            {
                printf("went inside");
                yrand[reset[l]][0] = -1210;
                speed[reset[l]] = 0;
                speed[reset[l + 1]] = 1;
                printf("%d %d", l, reset[l + 1]);
                tiles_timed_out[reset[l]] = false;
            }
            if (m)
            {
                iShowBMP2(0, 0, "cloudsup.bmp", 0);
            }
            else
            {
                iShowBMP2(0, 0, "cloudsup2.bmp", 0);
            }
            printf("m=m=m=%d\n\n\n\n\n\n\n\n\n\n\n", m);
        }
        if (resume)
        {
            iResumeTimer(0);
            resume_vel = 1;
        }
        printf("\n\n");

        for (int i = 0; i < 5; i++)
        {
            iShowBMP2(50 + i * 40, 900, scoreliteral[i], 0);
        }
        lives = -1;
        dup_lives = -1;
        for (int i = 0; i < M; i++)
        {
            iShowBMP2(267 + i * 40, 900, score_img2[score[i]], 0);
        }

        for (int i = 0; i < N; i++)
        {
            iShowBMP2(50 + (dup_lives)*55 + i * 40 + 100, 980, score_img2[showtimer[i]], 0);
        }
        iShowBMP2(50 + (dup_lives)*55 + 40, 980, "clock.bmp", 0);
    }
    if (startgamemode_2)
    {
        iShowBMP2(0, 0, "copium.bmp", 255);
        iShowBMP(650, 250, rick[ricki]);
    }
    if (pause)
    {
        iPauseTimer(0);
        resume_vel = 0;
        iShowBMP2(0, 0, "pause.bmp", 255);
    }

    if (retry)
    {
        iPauseTimer(0);
        iShowBMP2(0, 0, "retry.bmp", 255);
        for (int i = 0; i < no_of_dig; i++)
        {
            iShowBMP2(1025 + i * 50, 650, score_img[number[i]], 255);
        }

        for (int i = 0; i < no_of_dig_high; i++)
        {
            iShowBMP2(1025 + i * 50, 526, score_img[number_high[i]], 255);
        }
        iShowBMP2(1320, 760, "steve.bmp", 255);
    }
}




void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}





void resetgame()
{
    vel = vel_capture;
    dx = 50;
    dy = 200;
    dx1 = 1300, dy1 = 100;
    direc = 1;
    lives = no_of_lives;
    dup_lives = no_of_lives;
    int_score = 0;
    score[0] = '0';
    score[1] = '\0';
    showtimer[0] = 9;
    showtimer[1] = 0;
    timer_pos = true;
    time_counter_cloud = 0;
    time_counter = 0;
    resume_vel = 1;
    timer = 50;
    o = 4;
    no_of_dig = 0;
    no_of_dig_high = 0;
    N = 2;
    M = 1;
    score[0] = 0;

    for (int n = 0; n < id; n++)
    {
        flag[n] = true;
    }
    for (int i = 0; i < no_of_tracks; i++)
    {
        length_1[i] = rand() % 300; // 500 length is aesthetic to watch
        if (length_1[i] <= 200)
        {
            length_1[i] += 200;
        }
        xrand[i][0] = le + (i * ((1920 - 2 * le) / n)); // upper bound for tiles
        yrand[i][0] = ue;
    }

    for (int i = 0; i < tiles_at_a_time; i++)
    {
        printf("%d     %d\n", reset[i], speed[i]);
    }
    printf("\n");
    for (int n = 0; n < no_of_tracks; n++)
    {
        speed[n] = 0;
        reset[n] = 0;
    }

    int n = 0;

    while (n < tiles_at_a_time)
    {
        int randNum = rand() % no_of_tracks; // Generate a random number
        bool found = false;                  // assume the random number hasnt been generated

        // make sure the random number hasnt already been generated
        for (int h = 0; h < tiles_at_a_time; h++)
        {
            if (reset[h] == randNum)
            {
                found = true;
                break; // once we have located the number we dont need to continue checking
            }
        }

        if (!found)
        {
            reset[n] = randNum;
            n++;
        }
    }
    speed[reset[0]] = 1;
}

void iMouse(int button, int state, int mx, int my)
{

    if (menu)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 1790 && mx <= 1880 && my >= 960 && my <= 1040)
            {
                menu = false;
                settings = true;
            }
            else if (mx >= 790 && mx <= 1140 && my >= 500 && my <= 610)
            {

                menu = false;
                startgamemode_0 = true;
            }

            else if (mx >= 340 && mx <= 800 && my >= 100 && my <= 220)
            {
                menu = false;
                startgamemode_1 = true;
                PlaySound("sound2.wav", NULL, SND_ASYNC);
            }
            else if (mx >= 1150 && mx <= 1600 && my >= 100 && my <= 220)
            {
                menu = false;
                startgamemode_2 = true;
                PlaySound("rickroll.wav", NULL, SND_ASYNC);
            }
            else if (mx >= 1650 && mx <= 1740 && my >= 960 && my <= 1040)
            {
                menu = false;
                high_score = true;
            }
            else
            {
                ////// on menu if click outside button it turns black :(
            }
        }
    }
    if (high_score)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 50 && mx <= 170 && my >= 960 && my <= 1025)
            {
                menu = true;
                high_score = false;
            }
        }
    }
    if (settings)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 50 && mx <= 170 && my >= 960 && my <= 1025)
            {
                menu = true;
                settings = false;
            }
            if (mx >= 318 && mx <= 630 && my >= 568 && my <= 670)
            {
                speedhalf = true;
                speedfull = false;
                speeddouble = false;
                vel = 1;
                vel_capture = vel;
            }
            if (mx >= 800 && mx <= 1110 && my >= 568 && my <= 670)
            {
                speedhalf = false;
                speedfull = true;
                speeddouble = false;
                vel = 2;
                vel_capture = vel;
            }
            if (mx >= 1295 && mx <= 1700 && my >= 568 && my <= 670)
            {
                speedhalf = false;
                speedfull = false;
                speeddouble = true;
                vel = 4;
                vel_capture = vel;
            }
            if (mx >= 335 && mx <= 660 && my >= 140 && my <= 250)
            {
                live5 = true;
                live15 = false;
                live10 = false;
                resetgame();
                int *a = &no_of_lives;
                *a = 5;
                resetgame();
            }
            if (mx >= 800 && mx <= 1250 && my >= 140 && my <= 250)
            {
                live10 = true;
                live5 = false;
                live15 = false;
                int *a = &no_of_lives;
                *a = 10;
                resetgame();
            }
            if (mx >= 1290 && mx <= 1630 && my >= 140 && my <= 250)
            {
                live15 = true;
                live5 = false;
                live10 = false;
                int *a = &no_of_lives;
                *a = 15;
                resetgame();
            }
        }
    }
    if (startgamemode_0)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            for (int b = 0; b < tiles_at_a_time; b++)
            {
                if ((mx >= (int)xrand[reset[b]][1] && mx <= (int)xrand[reset[b]][3]) && (my <= (int)yrand[reset[b]][1] && my >= (int)yrand[reset[b]][0]))
                {
                    if (music_pop)
                    {
                        PlaySound("pop.wav", NULL, SND_ASYNC);
                    }

                    yrand[reset[b]][0] = -4999;
                    tiles_timed_out[reset[b]] = true;
                    printf("clicked");
                    int_score++;
                    int temp = int_score;
                    int temp2 = int_score;

                    M = 0;
                    while (temp2)
                    {
                        temp2 = temp2 / 10;
                        M++;
                    }
                    int i = M - 1;
                    while (temp)
                    {
                        int temp3 = temp % 10;
                        score[i] = temp3;
                        i--;
                        temp = temp / 10;
                    }
                }
            }
        }
    }
    if (startgamemode_1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            for (int b = 0; b < tiles_at_a_time; b++)
            {
                if ((mx >= (int)xrand[reset[b]][1] && mx <= (int)xrand[reset[b]][3]) && (my <= (int)yrand[reset[b]][1] && my >= (int)yrand[reset[b]][0]))
                {
                    yrand[reset[b]][0] = -4999;
                    tiles_timed_out[reset[b]] = true;
                    printf("clicked");
                    int_score++;
                    int temp = int_score;
                    int temp2 = int_score;

                    M = 0;
                    while (temp2)
                    {
                        temp2 = temp2 / 10;
                        M++;
                    }
                    int i = M - 1;
                    while (temp)
                    {
                        int temp3 = temp % 10;
                        score[i] = temp3;
                        i--;
                        temp = temp / 10;
                    }
                }
            }
        }
    }
    if (pause)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 558 && mx <= 1162 && my >= 580 && my <= 680)
            {
                pause = false;
                resume = true;
            }
            else if (mx >= 812 && mx <= 1110 && my >= 440 && my <= 540)
            {
                iResumeTimer(0);
                if (startgamemode_0)
                {
                    startgamemode_0 = false;
                    resetgame();
                }
                if (startgamemode_1)
                {
                    startgamemode_1 = false;
                    musicon = false;
                    if (!musicon)
                    {
                        PlaySound(0, 0, 0);
                    }
                    resetgame();
                }
                if (startgamemode_2)
                {
                    startgamemode_2 = false;
                    resetgame();
                }
                pause = false;
                menu = true; // when exit was clicked it input was being static for sometime. So i had to kill some time to not allow iMouse take another input for next scene
            }
            else
            {

            }
        }
    }
    if (retry)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 800 && mx <= 1130 && my >= 370 && my <= 450)
            {
                PlaySound(0, 0, 0);
                retry = false;
                iResumeTimer(0);
                resetgame();
            }
            if (mx >= 840 && mx <= 1085 && my >= 250 && my <= 330)
            {
                PlaySound(0, 0, 0);
                retry = false;
                iResumeTimer(0);
                // for(int i=0;i<60;i++){
                if (startgamemode_0)
                {
                    startgamemode_0 = false;
                    resetgame();
                }
                if (startgamemode_1)
                {
                    startgamemode_1 = false;
                    musicon = false;
                    if (!musicon)
                    {
                        PlaySound(0, 0, 0);
                    }
                    resetgame();
                }
                if (startgamemode_2)
                {
                    startgamemode_2 = false;
                    resetgame();
                }
                //}
                menu = true;
            }
        }
    }
}




void iKeyboard(unsigned char key)
{
    if (startgamemode_0)
    {
        if (key == ' ')
        {
            pause = true;
        }
        if (key == 'q')
        {
            FILE *ftp = fopen("high_score.txt", "a");
            fprintf(ftp, "%d\n", int_score);
            fclose(ftp);
            FILE *fhigh = fopen("high_score.txt", "r");
            int score = 0;
            int max = 0;
            while (fscanf(ftp, "%d\n", &score) != EOF)
            {
                if (score > max)
                {
                    max = score;
                }
            }

            int temp = int_score;
            int temp2 = int_score;

            while (temp != 0)
            {
                temp /= 10;
                no_of_dig++;
            }
            int i = 1;
            while (temp2 != 0)
            {
                number[no_of_dig - i] = temp2 % 10;
                temp2 /= 10;
                i++;
            }
            if (no_of_dig == 0)
            {
                number[0] = 0;
                no_of_dig = 1;
            }
            int temp3 = max;
            int temp4 = max;

            while (temp3 != 0)
            {
                temp3 /= 10;
                no_of_dig_high++;
            }
            int j = 1;
            while (temp4 != 0)
            {
                number_high[no_of_dig_high - j] = temp4 % 10;
                temp4 /= 10;
                j++;
            }
            if (no_of_dig_high == 0)
            {
                number_high[0] = 0;
                no_of_dig_high = 1;
            }

            fclose(ftp);
            iResumeTimer(0);
            startgamemode_0 = false;
            pause = false;
            menu = true;
        }
    }
    if (startgamemode_1)
    {
        if (key == ' ')
        {
            pause = true;
        }
        if (key == 'q')
        {
            FILE *ftp = fopen("high_score1.txt", "a");
            fprintf(ftp, "%d\n", int_score);
            fclose(ftp);
            FILE *fhigh = fopen("high_score1.txt", "r");
            int score = 0;
            int max = 0;
            while (fscanf(ftp, "%d\n", &score) != EOF)
            {
                if (score > max)
                {
                    max = score;
                }
            }

            int temp = int_score;
            int temp2 = int_score;

            while (temp != 0)
            {
                temp /= 10;
                no_of_dig++;
            }
            int i = 1;
            while (temp2 != 0)
            {
                number[no_of_dig - i] = temp2 % 10;
                temp2 /= 10;
                i++;
            }
            if (no_of_dig == 0)
            {
                number[0] = 0;
                no_of_dig = 1;
            }

            int temp3 = max;
            int temp4 = max;

            while (temp3 != 0)
            {
                temp3 /= 10;
                no_of_dig_high++;
            }
            int j = 1;
            while (temp4 != 0)
            {
                number_high[no_of_dig_high - j] = temp4 % 10;
                temp4 /= 10;
                j++;
            }
            if (no_of_dig_high == 0)
            {
                number_high[0] = 0;
                no_of_dig_high = 1;
            }

            fclose(ftp);

            resetgame();
            PlaySound(0, 0, 0);
            iResumeTimer(0);
            startgamemode_1 = false;
            pause = false;
            menu = true;
        }
    }
    if (startgamemode_2)
    {
        if (key == 'q')
        {
            PlaySound(0, 0, 0);
            menu = true;
            startgamemode_2 = false;
        }
        if (key == 'r')
        {
            for (int b = 0; b < no_of_tracks; b++)
            {
                yrand[b][0] = 0;
            }
        }
    }
    if (retry)
    {
        if (key == 'q')
        {
            resetgame();
            PlaySound(0, 0, 0);
            iResumeTimer(0);
            retry = false;
            startgamemode_1 = false;
            startgamemode_0 = false;
            pause = false;
            menu = true;
        }
    }
}





void timerupdate()
{
    if (o > 0)
    {
        o--;
    }
    else if (o == 0)
    {
        o = 4;
        timer--;
        if (timer == dup_timer - 15 && startgamemode_2 == true)
        {
            startgamemode_2 = false;
            PlaySound(0, 0, 0);
            menu = true;
        }
        if (timer % 30 == 0 && timer != 90)
        {
            if (startgamemode_1)
            {
                m = (!m);
            }
        }
        // printf("%d\n\n\n helloooooooo",timer);
        int temp = timer;
        int temp2 = timer;

        N = 0;
        while (temp2)
        {
            temp2 = temp2 / 10;
            N++;
        }
        int i = N - 1;
        while (temp)
        {
            int temp3 = temp % 10;
            showtimer[i] = temp3;
            i--;
            temp = temp / 10;
        }
        // showtimer[N]='\0';
    }
    if (timer == 0)
    {
        if (startgamemode_0)
        {
            FILE *ftp = fopen("high_score.txt", "a");
            fprintf(ftp, "%d\n", int_score);
            fclose(ftp);
            FILE *fhigh = fopen("high_score.txt", "r");
            int score = 0;
            int max = 0;
            while (fscanf(ftp, "%d\n", &score) != EOF)
            {
                if (score > max)
                {
                    max = score;
                }
            }

            int temp = int_score;
            int temp2 = int_score;

            while (temp != 0)
            {
                temp /= 10;
                no_of_dig++;
            }
            int i = 1;
            while (temp2 != 0)
            {
                number[no_of_dig - i] = temp2 % 10;
                temp2 /= 10;
                i++;
            }
            if (no_of_dig == 0)
            {
                number[0] = 0;
                no_of_dig = 1;
            }
            int temp3 = max;
            int temp4 = max;

            while (temp3 != 0)
            {
                temp3 /= 10;
                no_of_dig_high++;
            }
            int j = 1;
            while (temp4 != 0)
            {
                number_high[no_of_dig_high - j] = temp4 % 10;
                temp4 /= 10;
                j++;
            }
            if (no_of_dig_high == 0)
            {
                number_high[0] = 0;
                no_of_dig_high = 1;
            }
            //            for(int i=0;i<no_of_dig;i++){
            //                printf("%d\n",number[i]);
            //            }
            //            printf("High Score:: %d\n\n\n\n\n\n\n\n",max);
            fclose(ftp);
        }
        if (startgamemode_1)
        {
            FILE *ftp = fopen("high_score1.txt", "a");
            fprintf(ftp, "%d\n", int_score);
            fclose(ftp);
            FILE *fhigh = fopen("high_score1.txt", "r");
            int score = 0;
            int max = 0;
            while (fscanf(ftp, "%d\n", &score) != EOF)
            {
                if (score > max)
                {
                    max = score;
                }
            }

            int temp = int_score;
            int temp2 = int_score;

            while (temp != 0)
            {
                temp /= 10;
                no_of_dig++;
            }
            int i = 1;
            while (temp2 != 0)
            {
                number[no_of_dig - i] = temp2 % 10;
                temp2 /= 10;
                i++;
            }
            if (no_of_dig == 0)
            {
                number[0] = 0;
                no_of_dig = 1;
            }

            int temp3 = max;
            int temp4 = max;

            while (temp3 != 0)
            {
                temp3 /= 10;
                no_of_dig_high++;
            }
            int j = 1;
            while (temp4 != 0)
            {
                number_high[no_of_dig_high - j] = temp4 % 10;
                temp4 /= 10;
                j++;
            }
            if (no_of_dig_high == 0)
            {
                number_high[0] = 0;
                no_of_dig_high = 1;
            }
            //            for(int i=0;i<no_of_dig;i++){
            //                printf("%d\n",number[i]);
            //            }
            //            printf("High Score:: %d\n\n\n\n\n\n\n\n",max);
            fclose(ftp);
        }
        PlaySound("minecraft.wav", NULL, SND_ASYNC);
        retry = true;
    }
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    */
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_INSERT)
    {
        pause = true;
    }

    // place your codes for other keys here
}





void random_tiles()
{

    if (menu)
    {
        devi++; // :')
        if (devi >= 5)
        {
            devi = 0;
        }
        menui++;
        if (menui >= 2)
        {
            menui = 0;
        }
    }
    if (startgamemode_0)
    {
        timerupdate();

        for (int i = 0; i < 20; i++)
        {
            if (int_score == 10 * i)
            {
                vel += 0.03;
            }
        }

        if (time_counter < 90)
        {

            time_counter++;
        }
        else if (time_counter == 90)
        {
            printf("timersreset");
            time_counter = 0;

            for (int n = 0; n < id; n++)
            {
                flag[n] = true;
            }
            for (int i = 0; i < no_of_tracks; i++)
            {
                length_1[i] = rand() % 300; // 500 length is aesthetic to watch
                if (length_1[i] <= 200)
                {
                    length_1[i] += 200;
                }
                xrand[i][0] = le + (i * ((1920 - 2 * le) / n)); // upper bound for tiles
                yrand[i][0] = ue;
            }

            for (int i = 0; i < tiles_at_a_time; i++)
            {
                printf("%d     %d\n", reset[i], speed[i]);
            }
            printf("\n");
            for (int n = 0; n < no_of_tracks; n++)
            {
                speed[n] = 0;
                reset[n] = 0;
            }

            int n = 0;

            while (n < tiles_at_a_time)
            {
                int randNum = rand() % no_of_tracks; // Generate a random number
                bool found = false;                  // assume the random number hasnt been generated

                // make sure the random number hasnt already been generated
                for (int h = 0; h < tiles_at_a_time; h++)
                {
                    if (reset[h] == randNum)
                    {
                        found = true;
                        break; // once we have located the number we dont need to continue checking
                    }
                }

                // we have a new random number
                if (!found)
                {
                    reset[n] = randNum;
                    n++;
                }
            }
            speed[reset[0]] = 1;
        }
    }
    if (startgamemode_1)
    {

        timerupdate();

        for (int i = 0; i < 20; i++)
        {
            if (int_score == 10 * i)
            {
                vel += 0.03;
            }
        }

        if (time_counter < 90)
        {

            time_counter++;
        }
        else if (time_counter == 90)
        {
            printf("timersreset");
            time_counter = 0;

            for (int n = 0; n < id; n++)
            {
                flag[n] = true;
            }
            for (int i = 0; i < no_of_tracks; i++)
            {
                length_1[i] = rand() % 300; // 500 length is aesthetic to watch
                if (length_1[i] <= 200)
                {
                    length_1[i] += 200;
                }
                xrand[i][0] = le + (i * ((1920 - 2 * le) / n)); // upper bound for tiles
                yrand[i][0] = ue;
            }

            for (int i = 0; i < tiles_at_a_time; i++)
            {
                printf("%d     %d\n", reset[i], speed[i]);
            }
            printf("\n");
            for (int n = 0; n < no_of_tracks; n++)
            {
                speed[n] = 0;
                reset[n] = 0;
            }

            int n = 0;

            while (n < tiles_at_a_time)
            {
                int randNum = rand() % no_of_tracks; // Generate a random number
                bool found = false;                  // assume the random number hasnt been generated

                // make sure the random number hasnt already been generated
                for (int h = 0; h < tiles_at_a_time; h++)
                {
                    if (reset[h] == randNum)
                    {
                        found = true;
                        break; // once we have located the number we dont need to continue checking
                    }
                }

                // we have a new random number
                if (!found)
                {
                    reset[n] = randNum;
                    n++;
                }
            }
            speed[reset[0]] = 1;
        }
    }
    if (startgamemode_2)
    {
        timerupdate();
        ricki++;
        if (ricki >= 53)
        {
            ricki = 0;
        }
    }
}




int main()
{
    iSetTimer(vel * 109.8398, random_tiles); // 240
    iInitialize(1920, 1080, "Magic Tiles");
    return 0;
}
