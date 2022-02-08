#include <Eigen/Dense>
#include <tf2/buffer_core.h>
#include <tf2/exceptions.h>

using namespace std;

int main(int argc, char** argv)
{
  cout << "tf2 template" << endl;

  // Sample
  tf2::BufferCore buffer_core;
  const string frame_id = "world";
  const string child_frame_id = "base_link";
  const double t1 = 1.0;
  const double t2 = 3.0;
  const double ti = 2.0;
  const double x1 = 10.0;
  const double x2 = 20.0;
  geometry_msgs::TransformStamped tf_msg1;
  tf_msg1.header.frame_id = frame_id;
  tf_msg1.child_frame_id = child_frame_id;
  tf_msg1.header.stamp = ros::Time(t1, 0);
  tf_msg1.transform.translation.x = x1;
  tf_msg1.transform.translation.y = 0.0;
  tf_msg1.transform.translation.z = 0.0;
  tf_msg1.transform.rotation.w = 1.0;
  tf_msg1.transform.rotation.x = 0.0;
  tf_msg1.transform.rotation.y = 0.0;
  tf_msg1.transform.rotation.z = 0.0;

  geometry_msgs::TransformStamped tf_msg2;
  tf_msg2.header.frame_id = frame_id;
  tf_msg2.child_frame_id = child_frame_id;
  tf_msg2.header.stamp = ros::Time(t2, 0);
  tf_msg2.transform.translation.x = x2;
  tf_msg2.transform.translation.y = 0.0;
  tf_msg2.transform.translation.z = 0.0;
  tf_msg2.transform.rotation.w = 1.0;
  tf_msg2.transform.rotation.x = 0.0;
  tf_msg2.transform.rotation.y = 0.0;
  tf_msg2.transform.rotation.z = 0.0;

  bool set1 = buffer_core.setTransform(tf_msg1, "sample1", false);
  bool set2 = buffer_core.setTransform(tf_msg2, "sample1", false);

  try
  {
    geometry_msgs::TransformStamped interpolated =
      buffer_core.lookupTransform(frame_id, child_frame_id, ros::Time(ti, 0));
    cout << "interpolated" << endl <<  interpolated << endl;
  }
  catch(tf2::LookupException e)
  {
    cout << "Failed, interpolated: " << e.what() << endl;
  }
  catch(tf2::ConnectivityException e)
  {
    cout << "Failed, interpolated: " << e.what() << endl;
  }
  catch(tf2::ExtrapolationException e)
  {
    cout << "Failed, interpolated: " <<  e.what() << endl;
  }
  catch(tf2::InvalidArgumentException e)
  {
    cout << "Failed, interpolated: " << e.what() << endl;
  }

  return 0;
}
