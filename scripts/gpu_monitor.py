import argparse
import os
import time


def monitor_gpu(shell, interval):
    """Monitor the GPU memory usage periodically and start to execute the specified script when available.

    Args:
        shell (str): Path to the shell script.
        interval (int): The time interval (seconds) to monitor the GPU memory usage.
    """
    assert os.path.exists(shell)
    
    while True:
        gpu_memory_list = get_gpu_info()

        if max(gpu_memory_list) > 100:
            print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
            print(gpu_memory_list)
            time.sleep(interval)
        else:
            break
    
    os.system(shell)


def get_gpu_info():
    """Look up the current GPU memory usage via the nvidia-smi toolkit.

    Returns:
        list: Current memory usage of every GPU card.
    """
    gpu_memory_list = list()

    gpu_status = os.popen('nvidia-smi | grep %').read().split('|')

    for i in range(2, len(gpu_status), 4):
        gpu_memory = int(gpu_status[i].split('/')[0].split('M')[0].strip())
        gpu_memory_list.append(gpu_memory)

    return gpu_memory_list


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Monitor the GPU memory usage periodically and start to execute the specified script when available.")
    parser.add_argument("-s", "--shell", type=str, help="Path to the shell script.")
    parser.add_argument("-i", "--interval", type=int, default=300, help="The time interval (seconds) to monitor the GPU memory usage.")
    args = parser.parse_args()

    monitor_gpu(shell=args.shell, interval=args.interval)
