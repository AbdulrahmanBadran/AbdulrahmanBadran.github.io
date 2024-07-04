#pragma once
#pragma warning (disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "myStringLib.h"

using namespace std;


namespace myDateLib {

    struct stDate {
        short year;
        short month;
        short day;
    };

    struct stPeriod {

        stDate date1, date2;

    };

    enum enCompareDates { before = -1, equal = 0, after = 1 };

    enum enDays { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

    bool checkIfLeapYear(short year) {

        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }

    short dayInMonth(short year, short month) {

        if (month < 1 || month>12)
            return 0;

        int arrDayOfMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        return (month == 2) ? (checkIfLeapYear(year) ? 29 : 28) : arrDayOfMonth[month];

    }

    int numberOfDays(short year) {


        return checkIfLeapYear(year) ? 366 : 365;

    }

    int numberOfHours(short year, short month) {

        return dayInMonth(year, month) * 24;

    }

    int numberOfMinutes(short year, short month) {

        return numberOfHours(year, month) * 60;

    }

    int numberOfSeconds(short year, short month) {

        return numberOfMinutes(year, month) * 60;

    }

    short dayOfWeekOrder(short year, short month, short day) {

        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    }

    void whatDayIsIt(short year, short month, short day) {

        string arrOfDays[] = { " sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
        short dayOrder = dayOfWeekOrder(year, month, day);
        cout << arrOfDays[dayOrder];

    }

    enDays whatDayIsIt(stDate date) {

        string arrOfDays[] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
        short dayOrder = dayOfWeekOrder(date.year, date.month, date.day);
        return (enDays)dayOrder;

    }

    string monthsName(short monthNumber) {

        string monthName[] = { "jan","feb","march","april","may","june","july","aug","sep","oct","nov","dec" };

        return monthName[monthNumber - 1];

    }

    void monthCalender(short year, short month) {

        cout << "_______________" << monthsName(month) << "_____________________\n\n";

        cout << setw(5) << "Sun" << setw(5) << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat";
        cout << endl;


        switch ((enDays)dayOfWeekOrder(year, month, 1)) {

        case enDays::sunday:
        {
            cout << setw(5) << 1;
            break;
        }
        case enDays::monday:
        {
            cout << setw(10) << 1;
            break;
        }
        case enDays::tuesday:
        {
            cout << setw(15) << 1;
            break;
        }
        case enDays::wednesday:
        {
            cout << setw(20) << 1;
            break;
        }
        case enDays::thursday:
        {
            cout << setw(25) << 1;
            break;
        }
        case enDays::friday:
        {
            cout << setw(30) << 1;
            break;
        }
        case enDays::saturday:
        {
            cout << setw(35) << 1 << endl;
            break;
        }

        }

        for (short i = 1; i < dayInMonth(year, month); i++)
        {
            cout << setw(5) << i + 1;

            if ((enDays)dayOfWeekOrder(year, month, i + 1) == enDays::saturday)
                cout << endl;

        }
        cout << "\n____________________________________\n\n";

    }

    void yearCalender(short year) {

        cout << "------------------------------------------------\n";
        cout << "year " << year << " calender\n";
        cout << "------------------------------------------------\n";
        for (short i = 1; i < 13; i++)
        {
            monthCalender(year, i);
        }



    }

    short howManyDayFromTheBeginingOfTheYear(stDate date) {
        short c = 0;
        for (short i = 1; i < date.month; i++)
        {
            c += dayInMonth(date.year, i);
        }
        c += date.day;

        return c;
    }

    void totalDaysFromTheBeginingOfTheYearToDate(short year, short days) {
        short month = 1;
        short day = 0;
        for (short i = 1;; i++)
        {
            if (days - dayInMonth(year, i) >= 0) {
                days -= dayInMonth(year, i);
                month++;
            }
            else
            {
                day = days;
                break;
            }
        }

        cout << day << "/" << month << "/" << year;

    }

    void timeInYear(stDate date) {

        cout << "number of days " << "in [" << date.year << "] is " << numberOfDays(date.year);
        cout << endl;
        cout << "number of hours " << "in [" << date.year << "] is " << numberOfHours(date.year, date.month);
        cout << endl;

        cout << "number of minutes " << "in [" << date.year << "] is " << numberOfMinutes(date.year, date.month);
        cout << endl;

        cout << "number of seconds " << "in [" << date.year << "] is " << numberOfSeconds(date.year, date.month);


    }

    string dateToString(stDate date) {

        return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);

    }

    void printDayAndDate(stDate date) {
        whatDayIsIt(date.year, date.month, date.day);

        cout << " , ";

        dateToString(date);
    }

    void timeInMonth(short year, short month) {

        cout << "number of days " << "in [" << month << "] is " << dayInMonth(year, month);
        cout << endl;
        cout << "number of hours " << "in [" << month << "] is " << numberOfHours(year, month);
        cout << endl;

        cout << "number of minutes " << "in [" << month << "] is " << numberOfMinutes(year, month);
        cout << endl;

        cout << "number of seconds " << "in [" << month << "] is " << numberOfSeconds(year, month);



    }

    void addDaysToDate(stDate date) {

        int daysToAdd = 0;

        cout << "enter how many days you want to add: ";

        cin >> daysToAdd;

        short timeRemainingInMonth = dayInMonth(date.year, date.month) - date.day;

        if (daysToAdd <= timeRemainingInMonth) {

            date.day += daysToAdd;
            dateToString(date);
            return;

        }

        daysToAdd -= timeRemainingInMonth;

        short i = date.month + 1;
        date.day = 0;

        for (; i <= 12; i++)
        {

            if (daysToAdd <= dayInMonth(date.year, i)) {
                date.day += daysToAdd;
                date.month = i;
                dateToString(date);
                return;
            }

            if (i == 12 && daysToAdd > dayInMonth(date.year, i)) {
                daysToAdd -= dayInMonth(date.year, i);
                date.year++;
                i = 0;
                continue;
            }

            if (daysToAdd > dayInMonth(date.year, i)) {
                daysToAdd -= dayInMonth(date.year, i);

            }



        }



    }

    bool isDateOneBeforeDateTwo(stDate date1, stDate date2) {


        return date1.year > date2.year ? false : (date1.year == date2.year ? (date1.month > date2.month ? false : date1.month == date2.month ? (date1.day < date2.day) : true) : true);



    }

    bool isDateOneEqualToDateTwo(stDate date1, stDate date2) {

        return date1.year == date2.year ? (date1.month == date2.month ? date1.day == date2.day : false) : false;



    }

    bool isDateOneAfterDateTwo(stDate date1, stDate date2) {

        return !isDateOneEqualToDateTwo(date1, date2) && !isDateOneBeforeDateTwo(date1, date2);

    }

    bool isLastDayInMonth(short year, short month, short day) {

        return day == dayInMonth(year, month);

    }

    bool isLastMonthInYear(short month) {

        return month == 12;


    }

    bool isFirstdayInMonth(short day) {


        return day == 1;

    }

    bool isFirstMonthInYear(short month) {

        return month == 1;


    }

    bool isEndOfWeek(stDate date) {

        return whatDayIsIt(date) == enDays::saturday;


    }

    bool isWeekEnd(stDate date) {

        return whatDayIsIt(date) == enDays::friday || whatDayIsIt(date) == enDays::saturday;


    }

    bool isBusinessDay(stDate date) {

        return !isWeekEnd(date);


    }

    void increaseDateByOneDay(stDate& date) {

        if (isLastDayInMonth(date.year, date.month, date.day))
        {
            if (isLastMonthInYear(date.month))
            {
                date.month = 1;
                date.day = 1;
                date.year++;
            }
            else
            {
                date.day = 1;
                date.month++;

            }
        }
        else
        {
            date.day++;
        }
    }

    void increaseDateByXDay(stDate& date) {

        int howManyDays;
        cout << "how many days you want to increase the date:";
        cin >> howManyDays;

        for (int i = 0; i < howManyDays; i++)
        {
            increaseDateByOneDay(date);
        }


    }

    void increaseDateByOneWeek(stDate& date) {

        short remainingdayInMonth = (dayInMonth(date.year, date.month) - date.day);
        short week = 7;
        if (remainingdayInMonth < week)
        {
            week -= remainingdayInMonth;
            date.day = dayInMonth(date.year, date.month);
        }

        if (isLastDayInMonth(date.year, date.month, date.day))
        {
            if (isLastMonthInYear(date.month))
            {
                date.month = 1;
                date.day = week;
                date.year++;
            }
            else
            {
                date.day = week;
                date.month++;

            }
        }
        else
        {
            date.day += week;
        }


    }

    void increaseDateByXWeeks(stDate& date) {

        int howManyWeeks;
        cout << "how many weeks you want to increase the date:";
        cin >> howManyWeeks;

        for (int i = 0; i < howManyWeeks; i++)
        {
            increaseDateByOneWeek(date);
        }

    }

    void increaseDateByOneMonth(stDate& date) {

        if (isLastMonthInYear(date.month))
        {
            date.month = 1;
            date.year++;

        }
        else
            date.month++;

        short numberOfDaysInCurrentMonth = dayInMonth(date.year, date.month);

        if (date.day > numberOfDaysInCurrentMonth)
            date.day = numberOfDaysInCurrentMonth;


    }

    void increaseDateByXMonths(stDate& date) {

        int howManyMonths;
        cout << "how many months you want to increase the date:";
        cin >> howManyMonths;

        for (int i = 0; i < howManyMonths; i++)
        {
            increaseDateByOneMonth(date);
        }

    }

    void increaseDateByOneYear(stDate& date) {

        date.year++;

    }

    void increaseDateByXYears(stDate& date) {

        int howManyYears;
        cout << "how many years you want to increase the date:";
        cin >> howManyYears;

        date.year += howManyYears;

    }

    void increaseDateByOneDecade(stDate& date) {

        date.year += 10;

    }

    void increaseDateByXDecades(stDate& date) {

        int howManyDecades;
        cout << "how many decades you want to increase the date:";
        cin >> howManyDecades;

        date.year += (howManyDecades * 10);

    }

    void increaseDateByOneCentury(stDate& date) {

        date.year += 100;

    }

    void increaseDateByOneMellinnium(stDate& date) {

        date.year += 1000;

    }

    void decreaseDateByOneDay(stDate& date) {

        if (isFirstdayInMonth(date.day))
        {
            if (isFirstMonthInYear(date.month))
            {
                date.month = 12;
                date.year--;
            }

            else
                date.month--;


            date.day = dayInMonth(date.year, date.month);

        }
        else
            date.day--;



    }

    void decreaseDateByXDay(stDate& date) {

        int howManyDays;
        cout << "how many days you want to decrease the date:";
        cin >> howManyDays;

        for (int i = 0; i < howManyDays; i++)
        {
            decreaseDateByOneDay(date);
        }

    }

    void decreaseDateByOneWeek(stDate& date) {

        short week = 7;

        if (isFirstdayInMonth(date.day))
        {
            if (isFirstMonthInYear(date.month))
            {
                date.year--;
                date.month = 12;
                date.day = 25;


            }
            else
            {

                date.day = dayInMonth(date.year, date.month) - week;

            }


        }
        else
        {
            if (dayInMonth(date.year, date.month) <= week)
            {

                week -= dayInMonth(date.year, date.month) <= week;
                date.month--;
                date.day = dayInMonth(date.year, date.month) - week;

            }

            else
            {

                date.day = dayInMonth(date.year, date.month) - week;

            }
        }


    }

    void decreaseDateByXWeeks(stDate& date) {

        int howManyWeeks;
        cout << "how many weeks you want to decrease the date:";
        cin >> howManyWeeks;

        for (int i = 0; i < howManyWeeks; i++)
        {
            decreaseDateByOneWeek(date);
        }

    }

    void decreaseDateByOneMonth(stDate& date)
    {

        if (isFirstMonthInYear(date.month))
        {
            date.month = 12;
            date.year--;
            date.day = dayInMonth(date.year, date.month);
        }
        else
        {
            date.month--;
            date.day = dayInMonth(date.year, date.month);
        }


    }

    void decreaseDateByXMonths(stDate& date) {

        int howManyMonths;
        cout << "how many months you want to decrease the date:";
        cin >> howManyMonths;

        for (int i = 0; i < howManyMonths; i++)
        {
            decreaseDateByOneMonth(date);
        }

    }

    void decreaseDateByOneYear(stDate& date)
    {

        date.year--;

    }

    void decreaseDateByXYears(stDate& date)
    {

        int howManyYears;
        cout << "how many years you want to decrease the date:";
        cin >> howManyYears;

        date.year -= howManyYears;

    }

    void decreaseDateByOneDecade(stDate& date)
    {

        date.year -= 10;

    }

    void decreaseDateByXDecades(stDate& date)
    {

        int howManyDecades;
        cout << "how many decades you want to decrease the date:";
        cin >> howManyDecades;

        date.year -= (howManyDecades * 10);

    }

    void decreaseDateByOneCentury(stDate& date)
    {

        date.year -= 100;

    }

    void decreaseDateByOneMellinnium(stDate& date)
    {

        date.year -= 1000;

    }

    void printIfEndOfTheWeek(stDate date) {

        if (isEndOfWeek(date))
            cout << "yes , its the end of the week" << endl;
        else
            cout << "no , its not the end of the week" << endl;
    }

    void printIfWeekEnd(stDate date) {

        if (isWeekEnd(date))
            cout << "yes , its week end" << endl;
        else
            cout << "no , its not week end" << endl;
    }

    void printIfBusinessDay(stDate date) {

        if (isBusinessDay(date))
            cout << "yes , its business day" << endl;
        else
            cout << "no , its not business day" << endl;
    }

    short dayUntilTheEndOfWeek(stDate date) {

        short week = 7;

        return week - ((short)whatDayIsIt(date) + 1);

    }

    short dayUntilTheEndOfMonth(stDate date) {

        return dayInMonth(date.year, date.month) - date.day;

    }

    void printDayUntilTheEndOfWeek(stDate date) {

        cout << "day until the end of the week is : " << dayUntilTheEndOfWeek(date) << " day(s)" << endl;
    }

    void printDayUntilTheEndOfMonth(stDate date) {

        cout << "day until the end of the month is : " << dayUntilTheEndOfMonth(date) << " day(s)" << endl;

    }

    void printDayUntilTheEndOfTheYear(stDate date) {


        if (checkIfLeapYear(date.year))
            cout << "day until the end of the year is : " << 366 - howManyDayFromTheBeginingOfTheYear(date) << " day(s)" << endl;
        else
            cout << "day until the end of the year is : " << 365 - howManyDayFromTheBeginingOfTheYear(date) << " day(s)" << endl;



    }

    bool isValidDate(stDate date) {

        if (date.month < 1 || date.month>12)
            return false;

        if (date.day < 1 || date.day>31 || date.day > dayInMonth(date.year, date.month))
            return false;

        return true;

    }

    stDate readDate() {
        stDate date;
        do {
            cout << "please enter a day:";
            cin >> date.day;

            cout << "please enter a month:";
            cin >> date.month;

            cout << "please enter a year:";
            cin >> date.year;

            cout << endl;
            if (!isValidDate(date))
                cout << "please enter a valid date:\n\n";
        } while (!isValidDate(date));
        return date;

    }

    void swapDate(stDate& date1, stDate& date2) {

        stDate temp;
        temp.day = date1.day;
        temp.month = date1.month;
        temp.year = date1.year;

        date1.day = date2.day;
        date1.month = date2.month;
        date1.year = date2.year;

        date2.day = temp.day;
        date2.month = temp.month;
        date2.year = temp.year;
    }

    int differenceInDays(stDate date1, stDate date2) {

        short swapFlagValue = 1;

        if (!isDateOneBeforeDateTwo(date1, date2))
        {
            swapFlagValue = -1;
            swapDate(date1, date2);
        }




        if (isDateOneEqualToDateTwo(date1, date2))
            return 0;

        if (date1.month == date2.month && date1.year == date2.year)
            return abs(date1.day - date2.day);

        int remainingDayInMonth = dayInMonth(date1.year, date1.month) - date1.day;

        date1.day = 1;

        int differenceInDays = remainingDayInMonth;

        if (isLastMonthInYear(date1.month))
        {
            date1.month = 1;
            date1.year++;
        }
        else
            date1.month++;

        while (true) {

            if (!isDateOneEqualToDateTwo(date1, date2))
            {
                differenceInDays += dayInMonth(date1.year, date1.month);
                if (isLastMonthInYear(date1.month))
                {
                    date1.month = 1;
                    date1.year++;
                }
                else
                    date1.month++;
            }


            if (date1.month == date2.month && date1.year == date2.year)
            {
                differenceInDays += date2.day;
                return differenceInDays * swapFlagValue;
            }

        }
    }

    stDate getSystemDate() {

        stDate date;

        time_t t = time(0);

        tm* now = localtime(&t);

        date.year = now->tm_year + 1900;
        date.month = now->tm_mon + 1;
        date.day = now->tm_mday;

        return date;
    }

    void yourAgeInDays(stDate date1) {

        stDate todaysDate = getSystemDate();

        cout << differenceInDays(date1, todaysDate) << endl;

    }

    void readVacationPeriod(stDate& date1, stDate& date2) {

        cout << "vacation starts:\n";
        date1 = readDate();

        cout << "vacation ends\n";
        date2 = readDate();

    }

    stPeriod readPeriod()
    {
        stPeriod period;

        cout << "start date:\n\n";
        period.date1 = readDate();

        cout << "end date:\n\n";
        period.date2 = readDate();

        return period;

    }

    short calculateVacationDays(stDate dateFrom, stDate dateTo)
    {


        short dayCounter = 0;
        while (!isDateOneEqualToDateTwo(dateFrom, dateTo))
        {
            increaseDateByOneDay(dateFrom);

            if (isWeekEnd(dateFrom))
                continue;

            dayCounter++;
        }



        return dayCounter;

    }

    enCompareDates compareDates(stDate date1, stDate date2) {

        if (isDateOneBeforeDateTwo(date1, date2))
            return enCompareDates::before;

        else if (isDateOneEqualToDateTwo(date1, date2))
            return enCompareDates::equal;

        return enCompareDates::after;

    }

    stDate vacationReturnDate() {

        cout << "vacation starts:\n";
        stDate date = readDate();

        short vacationDay;
        cout << "please enter vacation days: ";
        cin >> vacationDay;

        for (; vacationDay >= 0;)
        {

            increaseDateByOneDay(date);
            if (isWeekEnd(date))
                continue;

            vacationDay--;

        }

        return date;
    }

    short calculatePeriodLengthInDays(stPeriod period1) {

        short days = 0;

        while (isDateOneBeforeDateTwo(period1.date1, period1.date2))
        {
            increaseDateByOneDay(period1.date1);

            days++;
        }

        return days;
    }

    bool isOverLap(stPeriod period1, stPeriod period2) {

        if (isDateOneBeforeDateTwo(period1.date2, period2.date1) || isDateOneBeforeDateTwo(period2.date2, period1.date1))
            return false;

        else
            return  true;

    }

    bool isDateInThisPeriod(stPeriod period, stDate date) {

        return !(compareDates(date, period.date2) == enCompareDates::after || compareDates(date, period.date2) == enCompareDates::before);

    }

    int countOverLapDays(stPeriod period1, stPeriod period2) {

        int days = 0;
        stPeriod period3;
        if (!isOverLap(period1, period2))
            return 0;

        if (compareDates(period1.date1, period2.date1) == enCompareDates::before)
        {
            period3.date1 = period1.date1;
            period3.date2 = period2.date2;
            return calculatePeriodLengthInDays(period3);
        }
        else
        {
            period3.date1 = period2.date1;
            period3.date2 = period1.date2;
            return calculatePeriodLengthInDays(period3);
        }



    }

    stDate stringToDate(string date) {

        stDate date1;


        vector<string>v = myStringLib::splitString(date, "/");


        date1.day = stoi(v[0]);

        date1.month = stoi(v[1]);

        date1.year = stoi(v[2]);




        return date1;


    }

    string readStringDate() {

        cout << "please enter the date dd/mm/yyyy?\n";

        string date;
        getline(cin >> ws, date);
        return date;
    }

    string dateFormating(stDate date) {

        cout << "choose one of the formats below:\n\n" <<
            "[1] dd/mm/yyyy\n" <<
            "[2] yyyy/mm/dd\n" <<
            "[3] mm/d/yyyy\n" <<
            "[4] dd-mm-yyyy\n" <<
            "[5] mm-dd-yyyy\n" <<
            "[6] day:dd, month:mm, year:yyyy\n";

        short choice;
        cin >> choice;

        switch (choice) {

        case 1: return dateToString(date);

        case 2: return  to_string(date.year) + "/" + to_string(date.month) + "/" + to_string(date.day);

        case 3: return to_string(date.month) + "/" + to_string(date.day) + "/" + to_string(date.year);

        case 4: return to_string(date.day) + "-" + to_string(date.month) + "-" + to_string(date.year);

        case 5: return to_string(date.month) + "-" + to_string(date.day) + "-" + to_string(date.year);

        case 6: return "day:" + to_string(date.day) + "," + "month:" + to_string(date.month) + "," + "year:" + to_string(date.year);

        }
    }



}