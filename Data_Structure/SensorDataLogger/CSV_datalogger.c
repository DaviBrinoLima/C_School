#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int time_stamp;
   int sensor_id;
   float read_value;
   char unit_meansurement[8];
   
} CSV_Format;

void append_reading(FILE *input_file, FILE *output_file) {
   CSV_Format sensor_data;
   
   while(fscanf(input_file, "%d %d %f %s", &sensor_data.time_stamp, &sensor_data.sensor_id, &sensor_data.read_value, sensor_data.unit_meansurement) == 1) {
      fprintf(output_file, "%i;%i;%f;%s\n", sensor_data.time_stamp, sensor_data.sensor_id, sensor_data.read_value, sensor_data.unit_meansurement);
   }
}

void list_sensor_data(FILE *output_file, int sensor_id, int initial_ts, int final_ts) {
   CSV_Format sensor_data;

   while ((fscanf(output_file, "%d %d %f %s", &sensor_data.time_stamp, &sensor_data.sensor_id, &sensor_data.read_value, sensor_data.unit_meansurement)==1) && ((sensor_data.time_stamp>=initial_ts) && (sensor_data.time_stamp<=final_ts)) && (sensor_data.sensor_id == sensor_id))
   {
     printf("Time Stamp = %d | Read value = %d%s", sensor_data.time_stamp, sensor_data.read_value,sensor_data.unit_meansurement);
   }
   
}


