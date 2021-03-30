#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
  // TODO: напишите здесь свой код ...
  auto node = new SinglyNode(e, top_);
  top_ = node;
  size_ += 1;
}

void LinkedStack::Pop() {
  if (top_ == nullptr) {
    throw std::logic_error("cannot pop out from empty stack");
  }
  auto curr = top_;
  top_ = top_->next;
  delete [] curr;
  size_ -= 1;

  // TODO: напишите здесь свой код ...
}

void LinkedStack::Clear() {
    if (size_ == 0){
        return;
    }
  // TODO: напишите здесь свой код ...
    auto curr = top_;
    for(int i = 0; i != size_; i++){
        top_ = top_->next;
        curr->next = nullptr;
        delete [] curr;
        curr = top_;
    }
    size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis