#include <utility>
#include <iostream>

#include "Schedule.h"


using namespace std::rel_ops;

/**
 *
 */
Schedule::Schedule()
    :head(nullptr),
    tail(nullptr),
    totalCredits(0)
{
}


/*Copy Constructor goes here
Implements a deep copy operation.
*/
Schedule::Schedule(const Schedule& src) ///**1st of big 3**
{
    Node* src_itr = src.head;

    this -> head = nullptr; ///Initialize each private member data
    this -> tail = nullptr; ///Initialize each private member data
    this -> totalCredits = 0; ///Initialize each private member data so start it as an empty list

    while (src_itr != nullptr)
    {
        this ->appendNoCheck(src_itr ->data); ///taking the (course)data from the course in (src_itr) node and adding it to this(Schedule linked list) linked list
        src_itr = src_itr -> next; ///move to the next node in the source list.
    }
}
/*Destructor goes here
It will traverse the or linked link,
grab data from data,
take data and store it in separate node then delete that
 
 
 */
Schedule::~Schedule() ///2ND of BIG 3
{

    Node *this_itr = nullptr; ///Used to walk through my link list. Every student has a schedule and every schedule has courses.
    Node *course_delete = nullptr; ///Used to delete the node or

    this_itr = this -> head; ///start at beginning of Schedule linked list

    while (this_itr != nullptr) ///Traversing..
    {
        course_delete = this_itr; ///point to same course
        this_itr = this_itr -> next; ///move to next course
        delete course_delete; ///delete current course
        course_delete = nullptr; ///Never have a pointer pointing to nothing
    }

    head = nullptr; ///Set private member data back to normal for no memory mistakes
    tail = nullptr; ///Set private member data back to normal for no memory mistakes
    totalCredits = 0; ///Set private member data back to normal for no memory mistakes

}

/**
 * @todo implement this function (it is similar to Review 01)
 */
void Schedule::appendNoCheck(Course course) ///I'm passing in a course that is NOT in the schedule names course
{

    // You need to implement linked list append operations
    Node *new_courseNode = nullptr; ///Making a Schedule Node
    new_courseNode = new Node(course); ///Storing the course data in the Schedule node

    if (this -> head == nullptr)
    {
        this -> head = new_courseNode;
        this -> tail = new_courseNode;
    }
    else ///otherwise add the new node to this linked list.
    {
        (this -> tail) -> next = new_courseNode; ///pointing to next node in CourseNode
        this -> tail = new_courseNode; ///tail is now equal to the next node in CourseNode. End of this linked list
    }

    totalCredits = this -> totalCredits + course.getCredits(); ///**Total amount of Credits in the Schedule**
    new_courseNode = nullptr; ///Never have a pointer pointing to anything and always reset pointers

}

/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    /* You need to replace the following line with
     the appropriate code
    * Check if adding this course would violate
    * the CREDIT_LIMIT. This is a evaluation of
    * (toAdd.getCredits() + this->totalCredits) > CREDIT_LIMIT
    */
    if (((course.getCredits()) + totalCredits) > CREDIT_LIMIT){return true;} ///If course along w/ existing courses would exceed 12 hours
    return false;
}

/**
 *
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    /* You need to replace the following line with
     the appropiate code (which involves a loop)
    * @returns true if while traversing the linked list
    *   of courses, a course with the same course number
    *   was found
    */
    Node* thisSame_itr = this -> head; ///Start at beginning when traversing

     while (thisSame_itr != nullptr)
    {
        if ((thisSame_itr -> data) == course) {return true;}
        thisSame_itr = thisSame_itr -> next; ///move to next course
    }
    return false;
}

/**
 *
 */
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        outs << "  - " << (it->data) << "\n";

        it = it->next;
    }
}

/**
 *
 */
Schedule& Schedule::operator=(const Schedule& rhs) ///********3RD of BIG 3
{
    /* If you chose to implement copyList and deallocateList,
     this function is done. Otherwise, you need to rewrite
     this function
     */
    if (this != &rhs) {
        deAllocateList(); /// 2nd out of big 3. Deallocating from destructor.

        copyList(rhs); /// 1st out of big 3. Shadow copy from constructor.
    }

    return *this;
}

/**
 *
 */
void Schedule::deAllocateList()
{
    Node *this_itr = nullptr; ///Used to walk through my link list. Every student has a schedule and every schedule has courses.
    Node *course_delete = nullptr; ///USed to delete the node or

    this_itr = this -> head; ///start at beginning of this linked list

    while (this_itr != nullptr)
    {
        course_delete = this_itr; ///point to same course
        this_itr = this_itr -> next; ///move to next course
        delete course_delete; ///delete current course
        course_delete = nullptr; ///Never have a pointer pointing to nothing
    }

    head = nullptr; ///Set things back to normal for no memory mistakes
    tail = nullptr;
    totalCredits = 0;

}

/**
 *
 */
void Schedule::copyList(const Schedule& rhs)
{
    Node* src_itr = rhs.head; ///Make sure to copy rhs into this linked list

    this -> head = nullptr; ///Initialize each private member data
    this -> tail = nullptr; ///Initialize each private member data
    this -> totalCredits = 0; ///Initialize each private member data so start it as an empty list

    while (src_itr != nullptr)
    {
        this ->appendNoCheck(src_itr ->data); ///taking the (course)data from the src_itr node and adding it to this linked list
        src_itr = src_itr -> next; ///move to the next node in the source list.
    }

}
