import matplotlib.pyplot as plt
import numpy as np

def extract_data_csv_file(file):
    with open(file, "r") as collected_data:
        file_line = collected_data.readline()
        
        temp = ""
        for i in range(21,25):
            temp+= file_line[i]
        
        time_and_temp = [{"Time": int(file_line[6]), "Temperatura": float(temp)}]

        while file_line:
            file_line = collected_data.readline()
            time = ""
            temp = ""

            for i in range(0,len(file_line)):
                if ((file_line[i].isnumeric() == True) and (i < 11)): 
                    time += file_line[i]

                elif ((file_line[i].isnumeric() == True) or (file_line[i] == ".")):
                    temp +=file_line[i]

                    
            if len(file_line)>0:        
                time_and_temp.append({"Time": int(time), "Temperature": float(temp)})

        return time_and_temp
        

def plot_graph(x,y,time_final,temp_max,set_point): 
    plt.plot(x,y, color = "k")
    plt.grid()
    
    
    plt.xlabel("Tempo (Min)", fontsize = "medium", fontweight = "heavy", fontstyle = "italic")
    plt.xlim(0,time_final)
    plt.xticks(np.arange(0,time_final,1))

    plt.ylabel("Temperatura (°C)", fontsize = "medium", fontweight = "heavy", fontstyle = "italic", )
    plt.ylim(0,temp_max)
    plt.yticks(np.arange(0,temp_max,5))
    plt.axhline(set_point, color = "r", linestyle = "dashed",label= "SetPoint")

    plt.title("Controle de Temperatura On/Off", fontsize = "large", fontweight = "heavy", fontstyle = "italic")
    plt.legend()

    plt.savefig("teste.png")
    plt.show()
    

def main():
    experiment_data = extract_data_csv_file("TaskControlKitchenOven/experiment_setpoint_95.csv")
    time = []
    temperature = []

    for i in range(1,len(experiment_data)-1):
        time.append(experiment_data[i].get("Time")/60)
        temperature.append(experiment_data[i].get("Temperature"))

    set_point= 95
    plot_graph(time,temperature,(time[len(time)-1]),(max(temperature)*1.05),set_point)
    

if __name__=="__main__":
    main()
        

