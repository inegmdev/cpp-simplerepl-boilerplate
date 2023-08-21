#include <simpleREPL.h>
#include <thread>
#include <chrono>

class StreamControl {
  public:
  string start(void);
  string stop(void);
  string status(void);
  private:
    bool _streamStatus = 0;
};

string StreamControl::start (void) {
  _streamStatus = 1;
  return "Stream has started.";
}

string StreamControl::stop (void) {
  _streamStatus = 0;
  return "Stream has stopped.";
}

string StreamControl::status (void) {
  if (_streamStatus == 1)
    return "Stream is on.";
  else
    return "Stream is off.";
}

void mainFunctionality() {
  while(1) {
    std::cout << "Main Task: every 5 seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }
}

void replTask() {
  StreamControl streamCtrl;
  while (
    interface(
      func(pack(&streamCtrl, &StreamControl::start), "stream_start", "To start the camera stream."),
      func(pack(&streamCtrl, &StreamControl::stop), "stream_stop", "To stop the camera stream."),
      func(pack(&streamCtrl, &StreamControl::status), "stream_status", "To get status of the camera stream.")
    )
  );
}

int main(void) {


  std::thread mainTask(mainFunctionality);
  std::thread repl(replTask);

  mainTask.join();
  repl.join();

  return 0;
}
