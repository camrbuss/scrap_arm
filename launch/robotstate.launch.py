
import os

import launch
import launch_ros.actions
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg_share = FindPackageShare('scrap_arm').find('scrap_arm')
    urdf_file = os.path.join(pkg_share, 'urdf', 'scrap_arm.urdf')

    rsp = launch_ros.actions.Node(package='robot_state_publisher',
                                  node_executable='robot_state_publisher',
                                  output='both',
                                  arguments=[urdf_file])
    osp = launch_ros.actions.Node(package='scrap_arm',
                                  node_executable='odrive_state',
                                  output='both')

    return launch.LaunchDescription([rsp, osp])