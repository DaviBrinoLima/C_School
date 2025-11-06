import matplotlib.pyplot as plt
import numpy as np
import math

def extract_data_csv_file(file):
    with open(file, "r") as collected_data:
        file_line = collected_data.readline()
        time_and_temp = [{}]

        while file_line:
            time = ""
            temp = ""

            for i in range(0,len(file_line)):
                if ((file_line[i].isnumeric() == True) and (i < 11)): 
                    time += file_line[i]

                elif ((file_line[i].isnumeric() == True) or (file_line[i] == ".")):
                    temp +=file_line[i]

                    
            if len(file_line)>0:        
                time_and_temp.append({"Time": int(time), "Temperature": float(temp)})

            file_line = collected_data.readline()

        return time_and_temp
        
def plot_graph(x,y,final_time,max_temp,set_point): 
    plt.rcParams["figure.figsize"] = (12,6)
    
    plt.plot(x,y, color = "k", linewidth=1)
    plt.grid()
    
    plt.xlabel("Tempo (Min)", fontsize = "medium", fontweight = "heavy", fontstyle = "italic")
    plt.xlim(0,final_time)
    plt.xticks(np.arange(0,(final_time+1),1))

    plt.ylabel("Temperatura (°C)", fontsize = "medium", fontweight = "heavy", fontstyle = "italic")
    plt.ylim(0,max_temp)
    plt.yticks(np.arange(0,(max_temp+6),5))
    
    plt.axhline(set_point, color = "r", linestyle = "dashed",label= "SetPoint", linewidth= 1.5, alpha= 0.5)

    # Funções usadas para plotar as linhas que delimitam o período usado para cálculo a potência média do forno em regime permanente
    # plt.axvline(31, color = "b", linestyle = "-",label= "Início do Período", linewidth= 1.5, alpha= 0.5) 
    # plt.axvline(36, color = "b", linestyle = "-",label= "Final do Período", linewidth= 1.5, alpha= 0.5) 

    plt.title("Controle de Temperatura On/Off", fontsize = "large", fontweight = "heavy", fontstyle = "italic")
    plt.legend()


    plt.savefig(f"TaskControlKitchenOven/ExperimentData/graph_On_Off_{set_point}.png")
    plt.show()

def main():
    set_point= 110
    
    experiment_data = extract_data_csv_file(f"TaskControlKitchenOven/ExperimentData/experiment_On_Off_{set_point}.csv")
    time = []
    temperature = []

    for i in range(1,len(experiment_data)):
        time.append(experiment_data[i].get("Time")/60)
        temperature.append(experiment_data[i].get("Temperature"))

    final_time = math.ceil((time[len(time)-1]))
    max_temp = math.ceil(max(temperature))

    plot_graph(time,temperature,final_time,max_temp,set_point)
    

if __name__=="__main__":
    main()
        

