#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CURRENT_YEAR 2023
#define YEARS_TRACKED 5
#define NUMBER_OF_MONTHS 12
#define RANDOM_RANGE_MINIMUM 0.5
#define RANDOM_RANGE_MAXIMUM 10

enum Months {
	January = 0,
	February = 1,
	March = 2,
	April = 3,
	May = 4,
	June = 5,
	July = 6,
	August = 7,
	September = 8,
	October = 9,
	November = 10,
	December = 11
};

float generate_random_float_in_range(float minimum, float maximum);
float calculate_total_rainfall_per_year(float * rainfall_per_year);
float calculate_total_rainfall_per_month(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS],
	 	size_t month);
void populate_rainfall_table(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]);
void print_rainfall_table(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]);
void print_rainfall_per_year(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]);
void print_rainfall_per_month(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]);
const char * month_to_string(enum Months month);

int main(int argc, char ** argv) {
	srand(time(NULL));
	float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS];
	populate_rainfall_table(rainfall_table);
	print_rainfall_table(rainfall_table);
	print_rainfall_per_year(rainfall_table);	
	print_rainfall_per_month(rainfall_table);
	return EXIT_SUCCESS;
}


float generate_random_float_in_range(float minimum, float maximum) { 
	return (((float)rand() / (float)(RAND_MAX)) * (maximum - minimum)) + minimum;
}


float calculate_total_rainfall_per_year(float * rainfall_per_year) {
	float sum = 0.0f;
	for (size_t i = 0; i < NUMBER_OF_MONTHS; i++) {
		sum += rainfall_per_year[i];
	}
	return sum;
}


float calculate_total_rainfall_per_month(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS],
		size_t month) {
	float sum = 0.0f;
	for (size_t i = 0; i < YEARS_TRACKED; i++) {
		sum += rainfall_table[i][month];
	}
	return sum;
}

void populate_rainfall_table(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]) {
	for (size_t i = 0; i < YEARS_TRACKED; i++) {
		for (size_t j = 0; j < NUMBER_OF_MONTHS; j++) {
			rainfall_table[i][j] = generate_random_float_in_range(
					RANDOM_RANGE_MINIMUM, 
					RANDOM_RANGE_MAXIMUM
			);
		}
	}
}


void print_rainfall_table(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]) {
	printf("\nRAINFALL DATA TABLE\n\n");

	printf("[\n");
	for (size_t i = 0; i < YEARS_TRACKED; i++) {
		printf("\t[ ");
		for (size_t j = 0; j < NUMBER_OF_MONTHS; j++) {
			printf("%.2f, ", rainfall_table[i][j]);
		}
		printf("],\n");
	}
	printf("]\n");
}

void print_rainfall_per_year(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]) {
	printf("\nRAINFALL PER YEAR\n\n");
	for (size_t i = 0; i < YEARS_TRACKED; i++) {
		printf("|%-*d| => ", 9, ((CURRENT_YEAR - YEARS_TRACKED) + i));
		printf("|%*.1f|\n", 9, calculate_total_rainfall_per_year(rainfall_table[i]));
	}	
}

void print_rainfall_per_month(float rainfall_table [YEARS_TRACKED][NUMBER_OF_MONTHS]) {
	printf("\nRAINFALL PER MONTH\n\n");
	for (enum Months i = 0; i < NUMBER_OF_MONTHS; i++) {
		printf("|%-*s| => |%*.1f|\n", 9, month_to_string(i), 
				9, calculate_total_rainfall_per_month(rainfall_table, i));
	}
}

const char * month_to_string(enum Months month) {
	switch (month) {
		case January: return "January";
		case February: return "February";
		case March: return "March";
		case April: return "April";
		case May: return "May";
		case June: return "June";
		case July: return "July";
		case August: return "August";
		case September: return "September";
		case October: return "October";
		case November: return "November";
		case December: return "December";
	}
}
