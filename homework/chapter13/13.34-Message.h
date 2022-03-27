#include <algorithm>
#include <set>
#include <string>
#include <utility>

class Folder;
class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message(Message &&m);
  Message &operator=(const Message &);
  Message &operator=(Message &&rhs);
  ~Message();

  void save(Folder &);
  void remove(Folder &);

  void add_folder(Folder *f) { folders.insert(f); }
  void delete_folder(Folder *f) { folders.erase(f); }
  void move_folders(Message *);

 private:
  std::string contents;
  std::set<Folder *> folders;

  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
  move_folders(&m);
}

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message &Message::operator=(Message &&rhs) {
  if (this != &rhs) {
    remove_from_Folders();
    contents = std::move(rhs.contents);
    move_folders(&rhs);
  }
  return *this;
}

Message::~Message() { remove_from_Folders(); }

class Folder {
  friend void swap(Message &lhs, Message &rhs);
  friend class Message;

 public:
  Folder();
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder() {
    for (auto i : messages) {
      remMsg(i);
    }
  };

  void addMsg(Message *m) { messages.insert(m); }
  void remMsg(Message *m) { messages.erase(m); }

 private:
  std::set<Message *> messages;
};

Folder::Folder(const Folder &f) { messages = f.messages; }

Folder &Folder::operator=(const Folder &f) {
  auto new_messages = f.messages;
  for (auto i : messages) {
    remMsg(i);
  }
  for (auto i : new_messages) {
    addMsg(i);
  }
  return *this;
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::remove_from_Folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}

void Message::move_folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
    f->addMsg(m);
    f->remMsg(this);
  }
  m->folders.clear();
}

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders) f->remMsg(&lhs);
  for (auto f : rhs.folders) f->remMsg(&rhs);
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders) f->addMsg(&lhs);
  for (auto f : rhs.folders) f->addMsg(&rhs);
}